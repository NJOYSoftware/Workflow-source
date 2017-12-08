#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>

#include "task.hpp"
#include "project.hpp"
#include "mainwindow.hpp"

namespace Ui {
class searchDialog;
}

class searchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit searchDialog(QWidget *parent, Task **currentTask, Project *currentProj);
    ~searchDialog();


private slots:
    void on_ledSearchString_textChanged(const QString &arg1);

    void on_cmbResults_activated(int index);

private:
    Ui::searchDialog *ui;
    Task **currentTaskPointer;
    Project *currentProjPointer;
    MainWindow *thisParent;

    std::deque<Task *> searchResults;
    void updateResults();
};

#endif // SEARCHDIALOG_H
