#ifndef TASKWINDOW_HPP
#define TASKWINDOW_HPP

#include <QWidget>
#include <cstdint>
#include <QString>
#include "task.hpp"
#include <project.hpp>
#include <mainwindow.hpp>
#include <QDialog>

namespace Ui {
  class taskWindow;
}

class taskWindow : public QDialog
{
  Q_OBJECT

public:
  explicit taskWindow(Task *newTask, QWidget *parent = 0);
  ~taskWindow();

  Task* thisTask;

private slots:
  void on_bbxButtons_accepted();

  void on_bbxButtons_rejected();

  void on_tedTaskText_textChanged();

private:
  Ui::taskWindow *ui;
};

#endif // TASKWINDOW_HPP
