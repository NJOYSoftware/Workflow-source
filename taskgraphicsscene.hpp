#ifndef TASKGRAPHICSSCENE_HPP
#define TASKGRAPHICSSCENE_HPP

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "task.hpp"
#include "mainwindow.hpp"

class MainWindow;

class TaskGraphicsScene : public QGraphicsScene
{
  Q_OBJECT

private:
  Task* taskShown;
  Task** currentPointer;
  QGraphicsSimpleTextItem *childTitle;

public:
  explicit TaskGraphicsScene(Task **currentTask, QObject* parent = 0);

  void setTaskShown(Task *newTask);
  Task* getTaskShown();

  void drawTaskShown();

protected:
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* btnReleased);

signals:
  void changeTask();

};

#endif // TASKGRAPHICSSCENE_HPP
