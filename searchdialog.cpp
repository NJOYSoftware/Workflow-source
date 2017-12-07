#include "searchdialog.hpp"
#include "ui_searchdialog.h"

searchDialog::searchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchDialog)
{
    ui->setupUi(this);
}

searchDialog::~searchDialog()
{
    delete ui;
}

void searchDialog::on_ledSearchString_textChanged(const QString &arg1)
{

}

void searchDialog::on_cmbResults_activated(const QString &arg1)
{

}
