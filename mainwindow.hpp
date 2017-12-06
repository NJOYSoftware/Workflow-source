#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "project.hpp"
#include <QGraphicsScene>
#include "taskgraphicsscene.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateWindow();
    void updateTree();
    void enableCurrentButtons();
    void clearAllScenes();
    void drawAllTasks();
    void setWindowTexts();
    void updatePageLabel();

    //debug new feature
    //void openFile();
    //QString openFilePath = "";

private slots:

    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_actionReport_Bug_triggered();

    void on_actionNew_Project_triggered();

    void on_btnModify_clicked();

    void on_btnComplete_clicked();

    void on_btnAddChild_clicked();

    void on_btnPrevTask_clicked();

    void on_taskChanged();

    void on_btnNewMaster_clicked();

    void on_actionHelp_triggered();

    void on_actionModify_Project_Title_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionAbout_Workflow_triggered();

    void on_btnPreviousPage_clicked();

    void on_btnNextPage_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
