#ifndef NEWTASKDIALOG_HPP
#define NEWTASKDIALOG_HPP

#include <QDialog>
#include "tasktemplate.hpp"

namespace Ui {
  class newTaskDialog;
}

class newTaskDialog : public QDialog
{
  Q_OBJECT

public:
  explicit newTaskDialog(TaskTemplate *newTaskTemplate, int_fast32_t newId, QWidget *parent = 0);
  ~newTaskDialog();
  TaskTemplate *selfTaskTemplate;

private slots:
  void on_btnOk_clicked();

private:
  Ui::newTaskDialog *ui;
};

#endif // NEWTASKDIALOG_HPP
