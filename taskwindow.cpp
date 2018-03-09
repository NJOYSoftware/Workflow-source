#include "taskwindow.hpp"
#include "ui_taskwindow.h"

#define MAXLENGTH 140

taskWindow::taskWindow(Task* newTask, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::taskWindow)
{
  QDialog::setModal(true);
  thisTask = newTask;
  QString idString = QString::number(thisTask->getId());

  ui->setupUi(this);
  ui->lblIdViewer->setText(idString);

  ui->ledTaskTitle->setText(thisTask->getTitle());
  ui->tedTaskText->setText(thisTask->getText());

}

taskWindow::~taskWindow()
{
  delete ui;
}

void taskWindow::on_bbxButtons_accepted()
{
  thisTask->setTitle(ui->ledTaskTitle->text());
  thisTask->setText(ui->tedTaskText->toPlainText());
  this->accept();
}

void taskWindow::on_bbxButtons_rejected()
{
    this->reject();
}


void taskWindow::on_tedTaskText_textChanged()
{
  if(ui->tedTaskText->toPlainText().length() > MAXLENGTH){
      QString text = ui->tedTaskText->toPlainText();
      quint32 difference = text.length() - MAXLENGTH;
      text.chop(difference);
      ui->tedTaskText->setText(text);
      QTextCursor cursor = ui->tedTaskText->textCursor();
      cursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
      ui->tedTaskText->setTextCursor(cursor);
    }
}
