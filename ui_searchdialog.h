/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_searchDialog
{
public:
    QComboBox *cmbResults;
    QLineEdit *ledSearchString;
    QLabel *lblSearchString;
    QLabel *lblNodes;
    QPushButton *btnClose;

    void setupUi(QDialog *searchDialog)
    {
        if (searchDialog->objectName().isEmpty())
            searchDialog->setObjectName(QStringLiteral("searchDialog"));
        searchDialog->resize(430, 229);
        cmbResults = new QComboBox(searchDialog);
        cmbResults->setObjectName(QStringLiteral("cmbResults"));
        cmbResults->setGeometry(QRect(10, 110, 351, 31));
        ledSearchString = new QLineEdit(searchDialog);
        ledSearchString->setObjectName(QStringLiteral("ledSearchString"));
        ledSearchString->setGeometry(QRect(10, 40, 331, 21));
        lblSearchString = new QLabel(searchDialog);
        lblSearchString->setObjectName(QStringLiteral("lblSearchString"));
        lblSearchString->setGeometry(QRect(10, 20, 151, 16));
        lblNodes = new QLabel(searchDialog);
        lblNodes->setObjectName(QStringLiteral("lblNodes"));
        lblNodes->setGeometry(QRect(10, 90, 121, 17));
        btnClose = new QPushButton(searchDialog);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(330, 190, 89, 25));

        retranslateUi(searchDialog);
        QObject::connect(btnClose, SIGNAL(clicked()), searchDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(searchDialog);
    } // setupUi

    void retranslateUi(QDialog *searchDialog)
    {
        searchDialog->setWindowTitle(QApplication::translate("searchDialog", "Search Task", Q_NULLPTR));
        lblSearchString->setText(QApplication::translate("searchDialog", "Task title contains:", Q_NULLPTR));
        lblNodes->setText(QApplication::translate("searchDialog", "Tasks found:", Q_NULLPTR));
        btnClose->setText(QApplication::translate("searchDialog", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class searchDialog: public Ui_searchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
