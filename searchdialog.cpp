#include "searchdialog.hpp"
#include "ui_searchdialog.h"


searchDialog::searchDialog(QWidget *parent, Task** currentTask, Project* currentProj) :
    QDialog(parent),
    ui(new Ui::searchDialog)
{
    thisParent = (MainWindow *)parent;
    currentTaskPointer = currentTask;
    currentProjPointer = currentProj;
    searchResults = currentProjPointer->getProjectTasks();

    ui->setupUi(this);
}

searchDialog::~searchDialog()
{
    delete ui;
}

void searchDialog::on_ledSearchString_textChanged(const QString &arg1)
{
    searchResults = currentProjPointer->getProjectTasks();
    if(!arg1.isEmpty()){
        for(int i = currentProjPointer->getProjectTasks().size() - 1; i >= 0; i--){
            if(!(searchResults[i] ->getTitle().contains(arg1, Qt::CaseInsensitive))){
                searchResults.erase(searchResults.begin() + i);
            }
        }
    }
    updateResults();
}

void searchDialog::on_cmbResults_activated(int index)
{
    *currentTaskPointer = searchResults[index];
    thisParent->updateWindow();
}

void searchDialog::updateResults(){
    ui->cmbResults->clear();
    for(unsigned int i = 0; i < searchResults.size(); i++){
        ui->cmbResults->addItem(searchResults[i]->getTitle());
    }
}
