/********************************************************************************
** Form generated from reading UI file 'wikiwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIKIWINDOW_H
#define UI_WIKIWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WikiWindow
{
public:
    QTextBrowser *wikiBrowser;
    QLabel *lblTitle;
    QPushButton *btnBack;
    QPushButton *btnForward;
    QPushButton *btnReload;

    void setupUi(QWidget *WikiWindow)
    {
        if (WikiWindow->objectName().isEmpty())
            WikiWindow->setObjectName(QStringLiteral("WikiWindow"));
        WikiWindow->resize(498, 639);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Desktop/Workflow Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        WikiWindow->setWindowIcon(icon);
        wikiBrowser = new QTextBrowser(WikiWindow);
        wikiBrowser->setObjectName(QStringLiteral("wikiBrowser"));
        wikiBrowser->setGeometry(QRect(10, 80, 481, 551));
        wikiBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        wikiBrowser->setSource(QUrl(QStringLiteral("qrc:/Wiki/Wiki Workflow/index.html")));
        wikiBrowser->setOpenExternalLinks(true);
        lblTitle = new QLabel(WikiWindow);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(10, 10, 461, 31));
        QFont font;
        font.setPointSize(17);
        lblTitle->setFont(font);
        lblTitle->setAlignment(Qt::AlignCenter);
        btnBack = new QPushButton(WikiWindow);
        btnBack->setObjectName(QStringLiteral("btnBack"));
        btnBack->setGeometry(QRect(10, 50, 75, 23));
        btnForward = new QPushButton(WikiWindow);
        btnForward->setObjectName(QStringLiteral("btnForward"));
        btnForward->setGeometry(QRect(390, 50, 75, 23));
        btnReload = new QPushButton(WikiWindow);
        btnReload->setObjectName(QStringLiteral("btnReload"));
        btnReload->setGeometry(QRect(190, 50, 91, 23));

        retranslateUi(WikiWindow);
        QObject::connect(btnBack, SIGNAL(clicked()), wikiBrowser, SLOT(backward()));
        QObject::connect(btnForward, SIGNAL(clicked()), wikiBrowser, SLOT(forward()));
        QObject::connect(btnReload, SIGNAL(clicked()), wikiBrowser, SLOT(reload()));

        QMetaObject::connectSlotsByName(WikiWindow);
    } // setupUi

    void retranslateUi(QWidget *WikiWindow)
    {
        WikiWindow->setWindowTitle(QApplication::translate("WikiWindow", "Help", Q_NULLPTR));
        lblTitle->setText(QApplication::translate("WikiWindow", "Workflow Wiki", Q_NULLPTR));
        btnBack->setText(QApplication::translate("WikiWindow", "Back", Q_NULLPTR));
        btnForward->setText(QApplication::translate("WikiWindow", "Forward", Q_NULLPTR));
        btnReload->setText(QApplication::translate("WikiWindow", "Reload Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WikiWindow: public Ui_WikiWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIKIWINDOW_H
