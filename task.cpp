#include "task.hpp"

#define OUTER_CURRENT_X_START 0
#define OUTER_CURRENT_Y_START 0
#define OUTER_CURRENT_WIDTH 360
#define OUTER_CURRENT_HEIGHT 216
#define INNER_CURRENT_X_START 30
#define INNER_CURRENT_Y_START 30
#define INNER_CURRENT_WIDTH 300
#define INNER_CURRENT_HEIGHT 156

Task::Task(Task* newMaster)
{
  setCompleted(false);
  setMaster(newMaster);
}

Task::~Task(){
}

quint32 Task::getId(){
  return Id;
}

void Task::setId(quint32 newId){
  Id = newId;
}

void Task::setTitle(QString newTitle){
  Title = newTitle;
}

QString Task::getTitle(){
  return Title;
}

void Task::setText(QString newText){
  Text = newText;
}

QString Task::getText(){
  return Text;
}

std::vector<Task*> Task::getChildren(){
  return children;
}

void Task::setMaster(Task* newMaster){
  Master = newMaster;
}

Task* Task::getMaster(){
  return Master;
}

bool Task::isCompleted(){
  return Completed;
}

bool Task::isCompletable(){
  bool tempCompletable = true;
  for (unsigned i = 0; i < children.size() && tempCompletable; i++){
      if( !children[i]->isCompleted() ){
          tempCompletable = false;
      }
    }
  return tempCompletable;
}

void Task::setCompleted(bool isCompleted){
  Completed = isCompleted;
}

Task* Task::addChild(quint32 nextId, Task* newMaster){
  Task* newChild = new Task(newMaster);
  newChild->setId(nextId);
  taskWindow* addChildWindow = new taskWindow(newChild);
  if(addChildWindow->exec() == taskWindow::Accepted){
      this->setCompleted(false);
      children.push_back(newChild);
      delete addChildWindow;
      return newChild;
  }
  else{
      delete newChild;
      delete addChildWindow;
      return Q_NULLPTR;
  }

}

void Task::addChild(Task *newChild){
  children.push_back(newChild);
}

void Task::drawAsCurrent(QGraphicsScene* currentScene){
    currentScene->addRect(OUTER_CURRENT_X_START, OUTER_CURRENT_Y_START, OUTER_CURRENT_WIDTH, OUTER_CURRENT_HEIGHT, QPen(Qt::black), (Completed ? QBrush(Qt::green) : QBrush(Qt::red)) );
    currentScene->addRect(INNER_CURRENT_X_START, INNER_CURRENT_Y_START, INNER_CURRENT_WIDTH, INNER_CURRENT_HEIGHT, QPen(Qt::black), QBrush(Qt::gray));
}

Task* Task::addMaster(quint32 nextId){
  Task* newMaster = new Task();
  newMaster->setId(nextId);
  taskWindow* addMasterWindow = new taskWindow(newMaster);
  if(addMasterWindow->exec()){
    this->setMaster(newMaster);
    newMaster->children.push_back(this);
    delete addMasterWindow;
    return newMaster;
  }
  else{
      delete newMaster;
      delete addMasterWindow;
      return Q_NULLPTR;
  }
}

quint32 Task::searchChild(quint32 id){
    quint32 indx = 0;
    while(children[indx]->getId() != id && indx < children.size()){
        indx++;
    }
    return indx;
}

void Task::deleteChild(quint32 indx){
    children.erase(children.begin() + indx);
}
