#include "task.hpp"

#define OUTER_CURRENT_X_START 0
#define OUTER_CURRENT_Y_START 0
#define OUTER_CURRENT_WIDTH 360
#define OUTER_CURRENT_HEIGHT 216
#define INNER_CURRENT_X_START 30
#define INNER_CURRENT_Y_START 30
#define INNER_CURRENT_WIDTH 300
#define INNER_CURRENT_HEIGHT 156

#define OUTER_CHILD_X_START 0
#define OUTER_CHILD_Y_START 0
#define OUTER_CHILD_WIDTH 240
#define OUTER_CHILD_HEIGHT 144
#define INNER_CHILD_X_START 15
#define INNER_CHILD_Y_START 15
#define INNER_CHILD_WIDTH 210
#define INNER_CHILD_HEIGHT 114

Task::Task(Task* newMaster)
{
  setCompleted(false);
  setMaster(newMaster);
}

qint32 Task::getId(){
  return Id;
}

void Task::setId(qint32 newId){
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

Task* Task::addChild(qint32 nextId, Task* newMaster){
  Task* newChild = new Task(newMaster);
  newChild->setId(nextId);
  taskWindow* addChildWindow = new taskWindow(newChild);
  if(addChildWindow->exec() == taskWindow::Accepted){
      children.push_back(newChild);
      return newChild;
  }
  else{
      return Q_NULLPTR;
  }

}

void Task::addChild(Task *newChild){
  children.push_back(newChild);
}

void Task::drawAsChild(QGraphicsScene* childScene){
  childScene->addRect(OUTER_CHILD_X_START, OUTER_CHILD_Y_START, OUTER_CHILD_WIDTH, OUTER_CHILD_HEIGHT, QPen(Qt::black), (Completed ? QBrush(Qt::green) : QBrush(Qt::red)));
  childScene->addRect(INNER_CHILD_X_START, INNER_CHILD_Y_START, INNER_CHILD_WIDTH, INNER_CHILD_HEIGHT, QPen(Qt::black), QBrush(Qt::gray));

  ChildText* TitleText = new ChildText();
  TitleText->setText(Title);
  TitleText->setFont(QFont("Helvetica", 16, 50));
  childScene->addItem(TitleText);

  TitleText->setPos((OUTER_CHILD_WIDTH - TitleText->boundingRect().width())/2, (OUTER_CHILD_HEIGHT - TitleText->boundingRect().height())/2);
}

void Task::drawAsCurrent(QGraphicsScene* currentScene){
    currentScene->addRect(OUTER_CURRENT_X_START, OUTER_CURRENT_Y_START, OUTER_CURRENT_WIDTH, OUTER_CURRENT_HEIGHT, QPen(Qt::black), (Completed ? QBrush(Qt::green) : QBrush(Qt::red)) );
    currentScene->addRect(INNER_CURRENT_X_START, INNER_CURRENT_Y_START, INNER_CURRENT_WIDTH, INNER_CURRENT_HEIGHT, QPen(Qt::black), QBrush(Qt::gray));
}

Task* Task::addMaster(qint32 nextId){
  Task* newMaster = new Task();
  newMaster->setId(nextId);
  taskWindow* addMasterWindow = new taskWindow(newMaster);
  if(addMasterWindow->exec()){
    this->setMaster(newMaster);
    newMaster->children.push_back(this);
    return newMaster;
  }
  else{
      return Q_NULLPTR;
  }
}

