#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "project.hpp"
#include "task.hpp"
#include "taskwindow.hpp"
#include "taskgraphicsscene.hpp"
#include "wikiwindow.hpp"
#include "searchdialog.hpp"
#include "filemanager.hpp"

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
#include <QCloseEvent>

#define CHILDREN_SCENE_COUNT 4
#define MAX_SIZE pow(16, NUM_OFFSET)

Project currentProj;
Task* currentTask = Q_NULLPTR;
TaskGraphicsScene* currentScene;
TaskGraphicsScene* childrenScenes[CHILDREN_SCENE_COUNT];
quint32 childrenPage = 0;

MainWindow::MainWindow(QString projString, QWidget *parent) :
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

    if(!projString.isEmpty()){
        currentProj.loadProject(projString);
        currentTask = currentProj.getProjectTasks().front();
        updateWindow();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    if(currentProj.getModified()){
        QMessageBox *information = new QMessageBox("Attention!", "Your project hasn't been saved since last changes. If you continue, they will be lost. Continue?", QMessageBox::Warning, QMessageBox::Ok, QMessageBox::No, QMessageBox::NoButton, this);
        information->exec();
        if(information->result() == QMessageBox::No){
            delete information;
            return;
        }
        delete information;
    }
    if(!currentProj.loadProject()){
        ui->lblProjectTitle->setText(currentProj.getTitle() );
        currentTask = currentProj.getProjectTasks()[0];
        updateWindow();
    }
}

void MainWindow::on_actionSave_triggered()
{
    currentProj.saveProject(currentProj.getSavePath());
}

void MainWindow::updateWindow()
{
  clearAllScenes();
  drawAllTasks();
  enableCurrentButtons();
  setWindowTexts();
  updateTree();
}


void MainWindow::on_actionNew_Project_triggered(){

    if(currentProj.getModified()){
        QMessageBox *information = new QMessageBox("Attention!", "Your project hasn't been saved since last changes. If you continue, they will be lost. Continue?", QMessageBox::Warning, QMessageBox::Ok, QMessageBox::No, QMessageBox::NoButton, this);
        information->exec();
        if(information->result() == QMessageBox::No){
            delete information;
            return;
        }
        delete information;
    }
    currentTask = new Task();
    currentProj.getProjectTasks().clear();
    QString tempProjTitle = QInputDialog::getText(this, "New Project", "Insert the title for the new project:", QLineEdit::Normal, "Project Title max 30 characters");
    currentProj.setTitle(tempProjTitle);

    currentTask->setId(0);
    taskWindow* newTaskWindow = new taskWindow(currentTask);
    if(tempProjTitle != NULL && newTaskWindow->exec() == taskWindow::Accepted){
        currentProj.addTaskAsChildren(currentTask);
        updateWindow();
        currentProj.setModified(true);
    }
    else{
        QMessageBox errorBox(QMessageBox::Warning, "Error in creating new project", "New project creation aborted!");
        errorBox.exec();
        delete currentTask;
    }
    delete newTaskWindow;
}

void MainWindow::on_btnModify_clicked()
{
    taskWindow* modifyWindow = new taskWindow(currentTask);
    modifyWindow->exec();
    currentProj.setModified(true);
    delete modifyWindow;
    updateWindow();
}

void MainWindow::on_btnComplete_clicked()
{   if(!currentTask->isCompleted()){
        if(currentTask->isCompletable()){
            currentTask->setCompleted(true);
            currentProj.setModified(true);
            updateWindow();
        }
        else{
            QMessageBox errorBox(QMessageBox::Warning, "Error", "The sub task are not completed. Please complete them first");
            errorBox.exec();
        }
    }
    else{
        currentTask->setCompleted(false);
        currentProj.setModified(true);

        updateWindow();
    }
}

static qint32 firstFreeID(){
    quint32 id = 0;
    while(currentProj.searchById(id) != NULL){
        id++;
    }
    return id;
}

void MainWindow::on_btnAddChild_clicked()
{
    if(currentProj.getProjectTasks().size() < MAX_SIZE){
        Task* child = currentTask->addChild(firstFreeID(), currentTask);
        if(child != Q_NULLPTR){
            currentProj.addTaskAsChildren(child);
            currentProj.setModified(true);
            updateWindow();
        }
        else{
            QMessageBox errorChildCreation(QMessageBox::Warning, "Error: The sub-task cannot be created!", "The creation of the sub-task encountered an error, please try again. If the problem subsist report it.");
            errorChildCreation.exec();
        }
    }
    else{
        QMessageBox errorMaxSize(QMessageBox::Warning, "Error: Max size reached!", "Your project reached the maximum size allowed. You can no longer create new Tasks.");
        errorMaxSize.exec();
    }
}

void MainWindow::on_taskChanged(){
  childrenPage = 0;
  updateWindow();
}

void MainWindow::on_btnPrevTask_clicked()
{
    currentTask = currentTask->getMaster();
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
  ui->btnDeleteTask->setEnabled(true);

  if(childrenPage < abs((qint32)(currentTask->getChildren().size() - 1)) / CHILDREN_SCENE_COUNT){
      ui->btnNextPage->setEnabled(true);
  }
  else{
      ui->btnNextPage->setDisabled(true);
  }

  ui->btnPreviousPage->setEnabled(childrenPage > 0);

  if(currentTask->isCompleted()){
    ui->btnComplete->setText("Uncomplete Task");
  }
  else{
    ui->btnComplete->setText("Complete Task");
  }

  ui->btnPrevTask->setEnabled(currentTask->getMaster() != Q_NULLPTR);
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
    if(currentProj.getProjectTasks().size() < MAX_SIZE){
        if( !currentTask->getMaster()){
            Task* child = currentTask->addMaster(firstFreeID());
            if(child != Q_NULLPTR){
                currentProj.addTaskAsMaster(child);
                currentTask = child;
                currentProj.setModified(true);
                childrenPage = 0;
                updateWindow();
            }
            else{
                QMessageBox errorChildCreation(QMessageBox::Warning, "Error: The sub-task cannot be created!", "The creation of the sub-task encountered an error, please try again. If the problem subsist report it.");
                errorChildCreation.exec();
            }
        }
        else{
            QMessageBox newMasterBox(QMessageBox::Warning, "Attention", "This current Task has already a Master Task");
            newMasterBox.exec();
        }
    }
    else{
        QMessageBox newMasterBox(QMessageBox::Warning, "Error: Max size reached!", "Your project reached the maximum size allowed. You can no longer create new Tasks.");
        newMasterBox.exec();
    }
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
    if(tempProjTitle != NULL){
        currentProj.setTitle(tempProjTitle);
        currentProj.setModified(true);
        updateWindow();
    }
    else{
        QMessageBox projectWarning(QMessageBox::Warning, "Warning", "Title modification has been cancelled!");
        projectWarning.exec();
    }
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
  quint32 condition = ceil(currentTask->getChildren().size()/CHILDREN_SCENE_COUNT);
  if(childrenPage < condition){
      childrenPage++;
  }
  updateWindow();
}

void MainWindow::updatePageLabel(){
    QString label = "Page: ";
    quint32 pageNumber;
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

void MainWindow::on_actionSearchNode_triggered()
{
    searchDialog *searchWindow = new searchDialog(this, &currentTask, &currentProj);
    searchWindow->show();
}

void MainWindow::on_actionSave_Project_as_triggered()
{
    currentProj.saveProject();
}

void MainWindow::closeEvent(QCloseEvent *event){
    if(currentProj.getModified()){
        QMessageBox *information = new QMessageBox("Attention!", "Your project hasn't been saved since last changes. If you continue, they will be lost. Continue?", QMessageBox::Warning, QMessageBox::Ok, QMessageBox::No, QMessageBox::NoButton, this);
        information->exec();
        if(information->result() == QMessageBox::No){
            delete information;
            event->ignore();
        }
    }
}

static void deleteTask(Task *t){
    for(int i = t->getChildren().size() - 1; i >= 0; i--){
        deleteTask(t->getChildren()[i]);
    }
    currentProj.deleteTask(currentProj.taskIndexByID(t->getId()));
    delete t;
}

static int deleteCurrentTask(){
    Task *tmp = currentTask;
    if(currentTask->getMaster() != Q_NULLPTR && currentProj.getProjectTasks().size() > 1){
        currentTask = currentTask->getMaster();
        currentTask->deleteChild(currentTask->searchChild(tmp->getId()));
        deleteTask(tmp);
        return 0;
    }
    else{
        QMessageBox errorBox(QMessageBox::Warning, "Warning", "Please add a master Task to this task in order to delete this task.");
        errorBox.exec();
        return 1;
    }
}

void MainWindow::on_btnDeleteTask_clicked()
{
    QMessageBox *information = new QMessageBox("Attention!", "Do you want to delete this Task and all of its sub-Tasks? This process cannot be reversed. They will be gone, forever!", QMessageBox::Warning, QMessageBox::Ok, QMessageBox::No, QMessageBox::NoButton, this);
    information->exec();
    if(information->result() == QMessageBox::Ok){
        if(!deleteCurrentTask()){
            updateWindow();
        }
    }
    delete information;
}
