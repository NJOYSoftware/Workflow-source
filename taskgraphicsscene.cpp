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
  if(btnReleased->button() == Qt::LeftButton){
      if(taskShown != Q_NULLPTR){
        *currentPointer = taskShown;
        emit changeTask();
      }
    }
}

void TaskGraphicsScene::drawTaskShown(){
    if(taskShown){
        taskShown->drawAsChild(this);
    }
}
