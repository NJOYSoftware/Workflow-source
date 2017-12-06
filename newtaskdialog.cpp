#include "newtaskdialog.hpp"
#include "ui_newtaskdialog.h"

newTaskDialog::newTaskDialog(TaskTemplate* newTaskTemplate, int_fast32_t newId, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::newTaskDialog)
{
  ui->setupUi(this);
  selfTaskTemplate = newTaskTemplate;
  ui->lblIdShower->setText(QString::number(newId));
}

newTaskDialog::~newTaskDialog()
{
  delete ui;
}

void newTaskDialog::on_btnOk_clicked()
{
  selfTaskTemplate->titleTemplate =  ui->lblTitle->text();
  selfTaskTemplate->idTemplate = ui->lblIdShower->text().toInt();
  selfTaskTemplate->textTemplate = ui->lblText->text();
  this->close();
}
