#ifndef TASK_HPP
#define TASK_HPP

#include <cstdint>
#include <QString>
#include <vector>
#include <QGraphicsScene>

class Task
{

private:
  quint32 Id;
  QString Title;
  QString Text;
  std::vector<Task*> children;
  Task* Master;
  bool Completed;

public:

  explicit Task(Task* newMaster = Q_NULLPTR);
  explicit Task(quint32 newid, QString newTitle, QString newText, Task* newMaster);
  ~Task();


  void setId(quint32 newId);
  quint32 getId();

  void setTitle(QString newTitle);
  QString getTitle();

  void setText(QString newText);
  QString getText();

  std::vector<Task*> getChildren();

  void setMaster(Task* newMaster);
  Task* getMaster();

  bool isCompleted();

  bool isCompletable();


  void setCompleted(bool isCompleted);
  Task *addChild(quint32 nextId, Task *newMaster);

  Task* addMaster(quint32 nextId);
  void addChild(Task* newChild);

  void drawAsCurrent(QGraphicsScene* currentScene);

  quint32 searchChild(quint32 id);
  void deleteChild(quint32 indx);

};

#include "taskwindow.hpp"


#endif // TASK_HPP
