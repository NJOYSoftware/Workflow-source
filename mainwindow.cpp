#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "project.hpp"
#include "task.hpp"
#include "taskwindow.hpp"
#include "taskgraphicsscene.hpp"
#include "wikiwindow.hpp"
#include "searchdialog.hpp"

#include <new>
#include <iostream>
#include <QMessageBox>
#include <vector>
#include <utility>
#include <QGraphicsScene>
#include <QInputDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>
#include <cmath>

#define CHILDREN_SCENE_COUNT 4

Project currentProj;
Task* currentTask;
TaskGraphicsScene* currentScene;
TaskGraphicsScene* childrenScenes[CHILDREN_SCENE_COUNT];
qint32 childrenPage = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentScene = new TaskGraphicsScene(&currentTask);

    for(int i = 0; i < CHILDREN_SCENE_COUNT; i++){
       childrenScenes[i] = new TaskGraphicsScene(&currentTask);
    }

    ui->grvCurrentTask->setScene(currentScene);

    ui->grvChild1->setScene(childrenScenes[0]);
    ui->grvChild2->setScene(childrenScenes[1]);
    ui->grvChild3->setScene(childrenScenes[2]);
    ui->grvChild4->setScene(childrenScenes[3]);

    for(unsigned i= 0; i < CHILDREN_SCENE_COUNT; i++){
        connect(childrenScenes[i], SIGNAL(changeTask()), this, SLOT(on_taskChanged()), Qt::QueuedConnection);
    }

    ui->lblDepTree->setText("/");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    if(currentProj.loadProject()){
        ui->lblProjectTitle->setText(currentProj.getTitle() );
        currentTask = currentProj.getProjectTasks()[0];
        updateWindow();
    }
}

void MainWindow::on_actionSave_triggered()
{
    currentProj.saveProject();
}

void MainWindow::updateWindow()
{
  clearAllScenes();
  drawAllTasks();
  enableCurrentButtons();
  setWindowTexts();
  updateTree();
}


void MainWindow::on_actionNew_Project_triggered()
{
  currentTask = new Task();

  currentProj.getProjectTasks().clear();

  QString tempProjTitle = QInputDialog::getText(this, "New Project", "Insert the title for the new project:", QLineEdit::Normal, "Project Title max 30 characters");
  currentProj.setTitle(tempProjTitle);

  currentTask->setId(0);
  taskWindow* newTaskWindow = new taskWindow(currentTask);
  if(newTaskWindow->exec() == taskWindow::Accepted){
      currentProj.addTaskAsChildren(currentTask);
      updateWindow();
  }
  else{
      QMessageBox errorBox(QMessageBox::Warning, "Error in creating new project", "New project creation aborted!");
      errorBox.exec();
  }
  delete(newTaskWindow);


}

void MainWindow::on_btnModify_clicked()
{
    taskWindow* modifyWindow = new taskWindow(currentTask);
    modifyWindow->exec();

    delete(modifyWindow);
    updateWindow();
}

void MainWindow::on_btnComplete_clicked()
{
    if(currentTask->isCompletable()){
        currentTask->setCompleted(true);
    }
    else{
        QMessageBox errorBox(QMessageBox::Warning, "Error", "The sub task are not completed. Please complete them first");
        errorBox.exec();
    }
    updateWindow();
}

void MainWindow::on_btnAddChild_clicked()
{
  Task* child = currentTask->addChild(currentProj.getProjectTasks().size(), currentTask);
  if(child){
      currentProj.addTaskAsChildren(child);
  }
  updateWindow();
}

void MainWindow::on_taskChanged(){
  childrenPage = 0;
  updateWindow();
}

void MainWindow::on_btnPrevTask_clicked()
{
    if(currentTask->getMaster() != Q_NULLPTR){
        currentTask = currentTask->getMaster();
    }
    childrenPage = 0;
    updateWindow();
}

void MainWindow::updateTree(){

  QString TaskTree = "";
  Task* masterPointer = currentTask;

  do{
      TaskTree = "/" + masterPointer->getTitle() + TaskTree;
      masterPointer = masterPointer->getMaster();
  } while(masterPointer != Q_NULLPTR);

  ui->lblDepTree->setText(TaskTree);
}

void MainWindow::enableCurrentButtons(){
  ui->btnModify->setEnabled(true);
  ui->btnComplete->setEnabled(true);
  ui->btnAddChild->setEnabled(true);
  ui->btnNewMaster->setEnabled(true);
  ui->btnPrevTask->setEnabled(true);
  if(childrenPage < abs((long long int)(currentTask->getChildren().size() - 1)) / CHILDREN_SCENE_COUNT){
      ui->btnNextPage->setEnabled(true);
  }
  else{
      ui->btnNextPage->setDisabled(true);
  }

  if(childrenPage > 0){
      ui->btnPreviousPage->setEnabled(true);
  }
  else{
      ui->btnPreviousPage->setDisabled(true);
  }
}

void MainWindow::clearAllScenes(){
  currentScene->clear();

  for (unsigned i = 0; i < CHILDREN_SCENE_COUNT; i ++){
      childrenScenes[i]->clear();
      childrenScenes[i]->setTaskShown(Q_NULLPTR);
  }
}

void MainWindow::drawAllTasks(){
  currentTask->drawAsCurrent(currentScene);

  for(unsigned i = 0; i < CHILDREN_SCENE_COUNT && i < currentTask->getChildren().size()-(CHILDREN_SCENE_COUNT*childrenPage); i++){
      childrenScenes[i]->setTaskShown(currentTask->getChildren()[i + CHILDREN_SCENE_COUNT * childrenPage]);
      childrenScenes[i]->drawTaskShown();
  }

}

void MainWindow::setWindowTexts(){
  ui->lblProjectTitle->setText(currentProj.getTitle());
  ui->lblCurrentTitle->setText(currentTask->getTitle());
  ui->tedCurrentText->setText(currentTask->getText());
  updatePageLabel();
}

void MainWindow::on_btnNewMaster_clicked()
{
    if( !currentTask->getMaster()){
        Task* child = currentTask->addMaster(currentProj.getProjectTasks().size() );
        if(child){
            currentProj.addTaskAsMaster(child);
            currentTask = child;
        }
    }
    else{
        QMessageBox newMasterBox(QMessageBox::Warning, "Attention", "This current Task has already a Master Task");
        newMasterBox.exec();
    }

    childrenPage = 0;
    updateWindow();
}

void MainWindow::on_actionHelp_triggered()
{
    WikiWindow* wikiWindow = new WikiWindow();
    wikiWindow->show();
}

void MainWindow::on_actionReport_Bug_triggered()
{
  QUrl mailURL("mailto:njoysoftware.company@gmail.com?subject=Bug/Problem Report&body=");
  QDesktopServices::openUrl(mailURL);
}

void MainWindow::on_actionModify_Project_Title_triggered()
{
  if(currentProj.getTitle() == "" && currentProj.getProjectTasks().size() == 0){
      QMessageBox projectWarning(QMessageBox::Warning, "Warning", "There is no project to modify!");
      projectWarning.exec();
      return;
  }
  QString tempProjTitle = QInputDialog::getText(this, "Change Project Title", "Change the Project title to:");
  currentProj.setTitle(tempProjTitle);

  updateWindow();
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_actionAbout_Workflow_triggered()
{
    QFileInfo fileInfo(qApp->applicationFilePath());
    QString boxTitle = "About " + qApp->applicationName();

    QString boxText = QString("<h3>%1</h3>").arg(qApp->applicationName());
    boxText += QString("<p><b>Version:</b> %1</p>").arg(qApp->applicationVersion());
    boxText += QString("<p><b>Qt Version:</b> %1</p>").arg(QT_VERSION_STR);
    boxText += QString("<p><b>Exe Name:</b> %1</p>").arg(fileInfo.fileName());
    boxText += QString("<p><b>File Path:</b> %1</p>").arg(fileInfo.filePath());
    boxText += QString("<p><b>Made by NJOY Software &copy;</b></p>");

    QMessageBox::about(this, boxTitle, boxText);
}

void MainWindow::on_btnPreviousPage_clicked()
{
  if(childrenPage > 0){
      childrenPage--;
  }
  updateWindow();
}

void MainWindow::on_btnNextPage_clicked()
{
  qint32 condition = ceil(currentTask->getChildren().size()/CHILDREN_SCENE_COUNT);
  if(childrenPage < condition){
      childrenPage++;
  }
  updateWindow();
}

void MainWindow::updatePageLabel(){
    QString label = "Page: ";
    qint32 pageNumber;
    QString firstNumber;
    QString secondNumber;

    pageNumber= (currentTask->getChildren().size() - 1)/CHILDREN_SCENE_COUNT + 1;
    if(currentTask->getChildren().size() == 0){
        firstNumber = "0";
        secondNumber = "0";
    }
    else{
        firstNumber = QString::number(childrenPage + 1);
        secondNumber = QString::number(pageNumber);
    }
    label.append(firstNumber);
    label.append("/");
    label.append(secondNumber);

    ui->lblChildrenPage->setText(label);
}

/* NEW feature Debug
void MainWindow::openFile(){

}

*/

void MainWindow::on_actionSearchNode_triggered()
{
    searchDialog *searchWindow = new searchDialog(this, &currentTask, &currentProj);
    searchWindow->show();
}
