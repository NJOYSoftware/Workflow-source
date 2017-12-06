#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <QString>
#include <cstdint>
#include "task.hpp"
#include <deque>


class Project{

private:
    QString projectTitle;
    std::deque<Task*> projectTasks;

public:
    Project();

    void setTitle(QString newTitle);
    QString getTitle();

    bool loadProject();
    //Debug for new feature
    //bool loadProjectFromFile(QString openFilePath);
    void saveProject();

    void addTaskAsChildren(Task *newTask);
    void addTaskAsMaster(Task *newTask);
    std::deque<Task *> getProjectTasks();
    Task* searchById(qint32 Id);
};

#endif // PROJECT_HPP
