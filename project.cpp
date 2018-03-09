#include "project.hpp"
#include "filemanager.hpp"
#include <fstream>
#include <QMessageBox>
#include <QCoreApplication>
#include <string>
#include <QFileDialog>
#include <QLocale>
#include <QFile>
#include <QTextStream>

#define COMPLETED 43
#define UNCOMPLETED 45

//Modify these numbers if you want to tweaks string length
//N.B. Any modification will make older projects not compatible and the project file will be larger
#define MAX_PROJ_TITLE_LENGTH 30
#define MAX_TASK_TITLE_LENGTH 20
#define MAX_TASK_TEXT_LENGTH  140


Project::Project(){

}

void Project::setTitle(QString newTitle){
    projectTitle = newTitle;
}

QString Project::getTitle(){
   return this->projectTitle;
}

void Project::setSavePath(QString newSavePath){
    savePath = newSavePath;
}

QString Project::getSavePath(){
    return savePath;
}

void Project::setModified(bool isModified){
    modified = isModified;
}

bool Project::getModified(){
    return modified;
}

void Project::saveProject(QString currentSavePath){
    if(currentSavePath.isEmpty()){
        currentSavePath = QFileDialog::getSaveFileName(nullptr, QString(getTitle()), QString(""), QString("Workflow Project File ( *.wfp)"));
        savePath = currentSavePath;
    }
    QFile filePath(currentSavePath);
    QChar* tempArrayPointer;
    QString tempString;
    Task* tempTask;

    if(filePath.open(QIODevice::WriteOnly | QIODevice::Truncate) ){
        QTextStream writeOnFile(&filePath);
      //Title
        for(int i = 0; i < projectTitle.size(); i++){
            tempArrayPointer = FileManager::CharToQChar(projectTitle[i].toLatin1());
            for(int j = 0; j < CHAR_OFFSET; j++){
                writeOnFile << tempArrayPointer[j];
              }
        }
        for (unsigned i = projectTitle.size(); i < MAX_PROJ_TITLE_LENGTH; i++){
          //NULL writer
            for(unsigned int j = 0; j < CHAR_OFFSET; j++){
                writeOnFile << 0;
            }
        }
      //Tasks
        for(unsigned i = 0; i < projectTasks.size(); i++){
            tempTask = projectTasks[i];
          //ID
            tempArrayPointer = FileManager::NumberToQChar(tempTask->getId());
            for(int j = 0; j < NUM_OFFSET; j++){
                writeOnFile << tempArrayPointer[j];
            }
          //Title
            tempString = tempTask->getTitle();
            for(int j = 0; j < tempString.size(); j++){
                tempArrayPointer = FileManager::CharToQChar(tempString[j].toLatin1());
                for(int k = 0; k < CHAR_OFFSET; k++){
                    writeOnFile << tempArrayPointer[k];
                }
            }
            for(int j = tempString.size(); j < MAX_TASK_TITLE_LENGTH; j++){
                for(int k = 0; k < CHAR_OFFSET; k++){
                    writeOnFile << 0;
                }
            }
          //Text
            tempString = projectTasks[i]->getText();
            for(int j = 0; j < tempString.size(); j++){
                tempArrayPointer = FileManager::CharToQChar(tempString[j].toLatin1());
                for(int k = 0; k < CHAR_OFFSET; k++){
                    writeOnFile << tempArrayPointer[k];
                }
            }
            for(int j = tempString.size(); j < MAX_TASK_TEXT_LENGTH; j++){
                for(int k = 0; k < CHAR_OFFSET; k++){
                    writeOnFile << 0;
                }
            }
          //Completed
            tempArrayPointer = FileManager::CharToQChar((tempTask->isCompleted()) ? COMPLETED : UNCOMPLETED);
            for(int j = 0; j < CHAR_OFFSET; j++){
                writeOnFile << tempArrayPointer[j];
            }
          //MasterId
            tempArrayPointer = ((tempTask->getMaster() != NULL) ? FileManager::NumberToQChar(tempTask->getMaster()->getId()) : FileManager::NumberToQChar(tempTask->getId()));
            for(int j = 0; j < NUM_OFFSET; j++){
                writeOnFile << tempArrayPointer[j];
            }
        }
        modified = 0;
    }
    else{
        QMessageBox errorWindow(QMessageBox::Warning, "Warning!", "The project hasn't been saved correctly!", QMessageBox::Ok);
        errorWindow.exec();
      }
}

bool Project::loadProject(QString projString){
    if(projString.isEmpty()){
        projString = QFileDialog::getOpenFileName(nullptr, QString("Open Project File"), QString(""), QString("Workflow Project(*.wfp)"));
    }
    QFile filePath(projString);
    savePath = projString;

    QString tempString = "";
    QString fileString;
    quint32 tempNumber = 0;

    Task* masterTask;

    qint32 fileIterator = 0;

    if(filePath.open(QIODevice::ReadOnly)){
        projectTasks.clear();
        QTextStream readFromFile(&filePath);
        fileString = readFromFile.readAll();
      //Title
        for(; fileIterator < MAX_PROJ_TITLE_LENGTH * CHAR_OFFSET; fileIterator+=CHAR_OFFSET){
            QChar tempArray[] = {fileString.at(fileIterator), fileString.at(fileIterator + 1)};
            tempNumber = FileManager::QCharToInt(tempArray, CHAR_OFFSET);
            if(tempNumber != 0){
                tempString.append(QChar(tempNumber));
            }
        }
        projectTitle = tempString;
        tempString.clear();
      //Tasks
          //ID
        while(fileIterator < fileString.size() ){
            Task* tempTask = new Task();
            QChar tempIDArray[NUM_OFFSET];
            for(int i = 0; i < NUM_OFFSET; i++){
                tempIDArray[NUM_OFFSET - i - 1] = fileString.at(fileIterator + i).toUpper();
            }
            tempNumber = FileManager::QCharToInt(tempIDArray, NUM_OFFSET);
            tempTask->setId(tempNumber);
            fileIterator += NUM_OFFSET;
          //Title
            for(int i = 0; i < MAX_TASK_TITLE_LENGTH; i++){
                QChar tempArray[] = {fileString.at(fileIterator), fileString.at(fileIterator + 1)};
                tempNumber = FileManager::QCharToInt(tempArray, CHAR_OFFSET);
                if(tempNumber != 0){
                    tempString.append(QChar(tempNumber));
                }
                fileIterator += CHAR_OFFSET;
            }
            tempTask->setTitle(tempString);
            tempString.clear();
          //Text
            for(int i = 0; i < MAX_TASK_TEXT_LENGTH; i++){
                QChar tempArray[] = {fileString.at(fileIterator), fileString.at(fileIterator + 1)};
                tempNumber = FileManager::QCharToInt(tempArray, CHAR_OFFSET);
                if(tempNumber != 0){
                    tempString.append(QChar(tempNumber));
                }
                fileIterator += CHAR_OFFSET;
            }
            tempTask->setText(tempString);
            tempString.clear();
          //Completed
            QChar tempCompletedArray[] = {fileString.at(fileIterator), fileString.at(fileIterator + 1)};
            tempNumber = FileManager::QCharToInt(tempCompletedArray, CHAR_OFFSET);
            tempTask->setCompleted(tempNumber == COMPLETED);
            fileIterator += CHAR_OFFSET;
          //MasterID
            QChar tempMasterArray[NUM_OFFSET];
            for(int j = 0; j < NUM_OFFSET; j++){
                tempMasterArray[j] = fileString[fileIterator + j];
            }
            tempNumber = FileManager::QCharToInt(tempMasterArray, NUM_OFFSET);
            if(tempNumber != tempTask->getId()){
                if((masterTask = searchById(tempNumber))){
                    tempTask->setMaster(masterTask);
                    masterTask->addChild(tempTask);
                }
            }
            else{
                tempTask->setMaster(Q_NULLPTR);
            }
            addTaskAsChildren(tempTask);
            fileIterator += NUM_OFFSET;
        }
        savePath = projString;
        return 0;
    }
    else{
        QMessageBox errorWindow(QMessageBox::Warning, "Warning!", "The project hasn't been loaded correctly!", QMessageBox::Ok);
        errorWindow.exec();
        return 1;
    }
}

std::deque<Task *> Project::getProjectTasks(){
  return projectTasks;
}

//Adds a new task to the deque as a children for
//No Task-dependance problems
void Project::addTaskAsChildren(Task* newTask){
  projectTasks.push_back(newTask);
}

//Adds the new task in the front of the deque
void Project::addTaskAsMaster(Task *newTask){
  projectTasks.push_front(newTask);
}

Task* Project::searchById(quint32 Id){
    Task* tempTask;
    for(unsigned int i = 0; i < projectTasks.size(); i++){
        tempTask = projectTasks[i];
        if(tempTask->getId() == Id){
            return tempTask;
        }
    }
    return Q_NULLPTR;
}

quint32 Project::taskIndexByID(quint32 id){
    quint32 indx = 0;
    while(projectTasks[indx]->getId() != id && indx < projectTasks.size()){
        indx++;
    }
    return indx;
}

void Project::deleteTask(quint32 indx){
    projectTasks.erase(projectTasks.begin() + indx);
}
