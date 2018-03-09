#include "taskgraphicsscene.hpp"

#include <QGraphicsSimpleTextItem>

#define OUTER_CHILD_X_START 0
#define OUTER_CHILD_Y_START 0
#define OUTER_CHILD_WIDTH 240
#define OUTER_CHILD_HEIGHT 144
#define INNER_CHILD_X_START 15
#define INNER_CHILD_Y_START 15
#define INNER_CHILD_WIDTH 210
#define INNER_CHILD_HEIGHT 114

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
        addRect(OUTER_CHILD_X_START, OUTER_CHILD_Y_START, OUTER_CHILD_WIDTH, OUTER_CHILD_HEIGHT, QPen(Qt::black), (taskShown->isCompleted() ? QBrush(Qt::green) : QBrush(Qt::red)));
        addRect(INNER_CHILD_X_START, INNER_CHILD_Y_START, INNER_CHILD_WIDTH, INNER_CHILD_HEIGHT, QPen(Qt::black), QBrush(Qt::gray));

        childTitle = addSimpleText(taskShown->getTitle(), QFont("Ubuntu", 16, 50));
        childTitle->setPos((OUTER_CHILD_WIDTH - childTitle->boundingRect().width())/2, (OUTER_CHILD_HEIGHT - childTitle->boundingRect().height())/2);
    }
}
