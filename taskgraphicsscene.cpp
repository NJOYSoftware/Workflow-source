#include "taskgraphicsscene.hpp"

TaskGraphicsScene::TaskGraphicsScene(Task** currentTask, QObject *parent) : QGraphicsScene(parent){
  currentPointer = currentTask;
  taskShown = Q_NULLPTR;
}

void TaskGraphicsScene::setTaskShown(Task *newTask){
  taskShown = newTask;
}

Task* TaskGraphicsScene::getTaskShown(){
  return taskShown;
}

void TaskGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *btnReleased){
  if(taskShown != Q_NULLPTR && btnReleased->button() == Qt::LeftButton){
        *currentPointer = taskShown;
        emit changeTask();
  }
}

void TaskGraphicsScene::drawTaskShown(){
    if(taskShown != Q_NULLPTR){
        taskShown->drawAsChild(this);
    }
}
