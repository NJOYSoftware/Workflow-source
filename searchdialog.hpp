#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include "task.hpp"
#include "project.hpp"

namespace Ui {
class searchDialog;
}

class searchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit searchDialog(QWidget *parent = 0);
    ~searchDialog();
    //pointer to current node
    //pointer to project

private slots:
    void on_ledSearchString_textChanged(const QString &arg1);

    void on_cmbResults_activated(const QString &arg1);

private:
    Ui::searchDialog *ui;
};

#endif // SEARCHDIALOG_H
