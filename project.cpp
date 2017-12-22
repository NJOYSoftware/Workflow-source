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

bool Project::loadProject(){
    QString projPath = QFileDialog::getOpenFileName(nullptr, QString("Open Project File"), QString(""), QString("Workflow Project(*.wfp)"));
    QFile filePath(projPath);

    QString tempString = "";
    QString fileString;
    qint32 tempNumber = 0;
    int tempByteArray[8];

    Task* masterTask;

    qint32 fileIterator = 0;

    if(filePath.open(QIODevice::ReadOnly)){
        projectTasks.clear();
        QTextStream readFromFile(&filePath);
        fileString = readFromFile.readAll();
      //Title
        for(; fileIterator < 30 * 8; fileIterator+=8){
            for(int j = 0; j < 8; j++){
                tempByteArray[j] = fileString[fileIterator + j].digitValue();
            }
            tempNumber = FileManager::BinaryToInt(tempByteArray);
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
            for(int i = 0; i < 8; i++){
                tempByteArray[i] = fileString[fileIterator + i].digitValue();
            }

            tempNumber = FileManager::BinaryToInt(tempByteArray);
            tempTask->setId(tempNumber);
            fileIterator += 8;

          //Title
            for(int i = 0; i < 20; i++){
                for(int j = 0; j < 8; j++){
                    tempByteArray[j] = fileString[fileIterator + j].digitValue();
                }
                tempNumber = FileManager::BinaryToInt(tempByteArray);
                if(tempNumber != 0){
                    tempString.append(QChar(tempNumber));
                }

                fileIterator += 8;
            }
            tempTask->setTitle(tempString);
            tempString.clear();
          //Text
            for(int i = 0; i < 140; i++){
                for(int j = 0; j < 8; j++){
                    tempByteArray[j] = fileString[fileIterator + j].digitValue();
                }
                tempNumber = FileManager::BinaryToInt(tempByteArray);
                if(tempNumber != 0){
                    tempString.append(QChar(tempNumber));
                }

                fileIterator += 8;
            }
            tempTask->setText(tempString);
            tempString.clear();
          //Completed
            for(int j = 0; j < 8; j++){
                tempByteArray[j] = fileString[fileIterator + j].digitValue();
            }
            tempNumber = FileManager::BinaryToInt(tempByteArray);
            if(tempNumber == 43){
                tempTask->setCompleted(true);
            }
            else{
                tempTask->setCompleted(false);
            }

            fileIterator += 8;
          //MasterID
            for(int j = 0; j < 8; j++){
                tempByteArray[j] = fileString[fileIterator + j].digitValue();
            }
            tempNumber = FileManager::BinaryToInt(tempByteArray);
            if(tempNumber != tempTask->getId()){
                if((masterTask = searchById(tempNumber))){
                    tempTask->setMaster(masterTask);
                    masterTask->addChild(tempTask);
                }
            }
            else{
                tempTask->setMaster(0);
            }

            addTaskAsChildren(tempTask);

            fileIterator += 8;
        }
        savePath = projPath;
        return 0;
    }
    else{
        QMessageBox errorWindow(QMessageBox::Warning, "Warning!", "The project hasn't been loaded correctly!", QMessageBox::Ok);
        errorWindow.exec();
        return 1;
    }

}

void Project::saveProject(QString currentSavePath){
    if(currentSavePath.isEmpty()){
        currentSavePath = QFileDialog::getSaveFileName(nullptr, QString(getTitle()), QString(""), QString("Workflow Project File ( *.wfp)"));
        savePath = currentSavePath;
    }
    QFile filePath(currentSavePath);
    int* tempArrayPointer;
    QString tempString;
    Task* tempTask;

    if(filePath.open(QIODevice::WriteOnly | QIODevice::Truncate) ){
        QTextStream writeOnFile(&filePath);
      //Title
        for(int i = 0; i < projectTitle.size(); i++){
            tempArrayPointer = FileManager::IntToBinary(projectTitle[i].toLatin1());
            for(int j = 0; j < 8; j++){
                writeOnFile << tempArrayPointer[j];
              }
        }
        for (unsigned i = projectTitle.size(); i < 30; i++){
          //NULL writer
            for(int i = 0; i < 8; i++){
                writeOnFile << 0;
            }
        }
      //Tasks
        for(unsigned i = 0; i < projectTasks.size(); i++){
            tempTask = projectTasks[i];
          //ID
            tempArrayPointer = FileManager::IntToBinary(tempTask->getId());
            for(int j = 0; j < 8; j++){
                writeOnFile << tempArrayPointer[j];
            }
          //Title
            tempString = tempTask->getTitle();
            for(int j = 0; j < tempString.size(); j++){
                tempArrayPointer = FileManager::IntToBinary(tempString[j].toLatin1());
                for(int k = 0; k < 8; k++){
                    writeOnFile << tempArrayPointer[k];
                }
            }
            for(int j = tempString.size(); j < 20; j++){
                for(int k = 0; k < 8; k++){
                    writeOnFile << 0;
                }
            }
          //Text
            tempString = projectTasks[i]->getText();
            for(int j = 0; j < tempString.size(); j++){
                tempArrayPointer = FileManager::IntToBinary(tempString[j].toLatin1());
                for(int k = 0; k < 8; k++){
                    writeOnFile << tempArrayPointer[k];
                }
            }
            for(int j = tempString.size(); j < 140; j++){
                for(int k = 0; k < 8; k++){
                    writeOnFile << 0;
                }
            }
          //Completed
            if(tempTask->isCompleted()){
                tempArrayPointer = FileManager::IntToBinary(COMPLETED);
                for(int j = 0; j < 8; j++){
                    writeOnFile << tempArrayPointer[j];
                }
            }
            else{
                tempArrayPointer = FileManager::IntToBinary(UNCOMPLETED);
                for(int j = 0; j < 8; j++){
                    writeOnFile << tempArrayPointer[j];
                }
            }
          //MasterId
            if(tempTask->getMaster()){
                tempArrayPointer = FileManager::IntToBinary(tempTask->getMaster()->getId());
                for(int j = 0; j < 8; j++){
                    writeOnFile << tempArrayPointer[j];
                }
            }
            else{
                tempArrayPointer = FileManager::IntToBinary(tempTask->getId());
                for(int j = 0; j < 8; j++){
                    writeOnFile << tempArrayPointer[j];
                }
            }
        }
        modified = 0;
    }
    else{
        QMessageBox errorWindow(QMessageBox::Warning, "Warning!", "The project hasn't been saved correctly!", QMessageBox::Ok);
        errorWindow.exec();
      }

}

/* Debug function for loading a project from a file
bool Project::loadProjectFromFile(QString openFilePath){
    QString projPath = QFileDialog::getOpenFileName(nullptr, QString("Open Project File"), QString(""), QString("Workflow Project(*.wfp)"));
    QFile filePath(projPath);

    QString tempString = "";
    QString fileString;
    qint32 tempNumber = 0;
    int tempByteArray[8];

    Task* masterTask;

    qint32 fileIterator = 0;

    if(filePath.open(QIODevice::ReadOnly)){
        projectTasks.clear();
        QTextStream readFromFile(&filePath);
        fileString = readFromFile.readAll();
      //Title
        for(; fileIterator < 30 * 8; fileIterator+=8){
            for(int j = 0; j < 8; j++){
                tempByteArray[j] = fileString[fileIterator + j].digitValue();
            }
            tempNumber = FileManager::BinaryToInt(tempByteArray);
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
            for(int i = 0; i < 8; i++){
                tempByteArray[i] = fileString[fileIterator + i].digitValue();
            }

            tempNumber = FileManager::BinaryToInt(tempByteArray);
            tempTask->setId(tempNumber);
            fileIterator += 8;

          //Title
            for(int i = 0; i < 20; i++){
                for(int j = 0; j < 8; j++){
                    tempByteArray[j] = fileString[fileIterator + j].digitValue();
                }
                tempNumber = FileManager::BinaryToInt(tempByteArray);
                if(tempNumber != 0){
                    tempString.append(QChar(tempNumber));
                }

                fileIterator += 8;
            }
            tempTask->setTitle(tempString);
            tempString.clear();
          //Text
            for(int i = 0; i < 140; i++){
                for(int j = 0; j < 8; j++){
                    tempByteArray[j] = fileString[fileIterator + j].digitValue();
                }
                tempNumber = FileManager::BinaryToInt(tempByteArray);
                if(tempNumber != 0){
                    tempString.append(QChar(tempNumber));
                }

                fileIterator += 8;
            }
            tempTask->setText(tempString);
            tempString.clear();
          //Completed
            for(int j = 0; j < 8; j++){
                tempByteArray[j] = fileString[fileIterator + j].digitValue();
            }
            tempNumber = FileManager::BinaryToInt(tempByteArray);
            if(tempNumber == 43){
                tempTask->setCompleted(true);
            }
            else{
                tempTask->setCompleted(false);
            }

            fileIterator += 8;
          //MasterID
            for(int j = 0; j < 8; j++){
                tempByteArray[j] = fileString[fileIterator + j].digitValue();
            }
            tempNumber = FileManager::BinaryToInt(tempByteArray);
            if(tempNumber != tempTask->getId()){
                if((masterTask = searchById(tempNumber))){
                    tempTask->setMaster(masterTask);
                    masterTask->addChild(tempTask);
                }
            }
            else{
                tempTask->setMaster(0);
            }

            addTaskAsChildren(tempTask);

            fileIterator += 8;
        }
        return 1;
    }
    else{
        QMessageBox errorWindow(QMessageBox::Warning, "Warning!", "The project hasn't been loaded correctly!", QMessageBox::Ok);
        errorWindow.exec();
        return 0;
    }

}
*/
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

Task* Project::searchById(qint32 Id){
    Task* tempTask;
    for(unsigned int i = 0; i < projectTasks.size(); i++){
        tempTask = projectTasks[i];
        if(tempTask->getId() == Id){
            return tempTask;
        }
    }
    return Q_NULLPTR;
}
