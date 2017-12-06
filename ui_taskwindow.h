/********************************************************************************
** Form generated from reading UI file 'taskwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKWINDOW_H
#define UI_TASKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_taskWindow
{
public:
    QFrame *line;
    QLabel *lblWindowLabel;
    QLabel *lblIdLabel;
    QLabel *lblTitleLabel;
    QLabel *lblTextLabel;
    QLabel *lblIdViewer;
    QLineEdit *ledTaskTitle;
    QTextEdit *tedTaskText;
    QFrame *line_2;
    QFrame *line_3;
    QDialogButtonBox *bbxButtons;

    void setupUi(QWidget *taskWindow)
    {
        if (taskWindow->objectName().isEmpty())
            taskWindow->setObjectName(QStringLiteral("taskWindow"));
        taskWindow->resize(640, 501);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Desktop/Workflow Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        taskWindow->setWindowIcon(icon);
        line = new QFrame(taskWindow);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 60, 641, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lblWindowLabel = new QLabel(taskWindow);
        lblWindowLabel->setObjectName(QStringLiteral("lblWindowLabel"));
        lblWindowLabel->setGeometry(QRect(40, 9, 520, 51));
        QFont font;
        font.setPointSize(23);
        lblWindowLabel->setFont(font);
        lblWindowLabel->setAlignment(Qt::AlignCenter);
        lblWindowLabel->setTextInteractionFlags(Qt::NoTextInteraction);
        lblIdLabel = new QLabel(taskWindow);
        lblIdLabel->setObjectName(QStringLiteral("lblIdLabel"));
        lblIdLabel->setGeometry(QRect(20, 100, 71, 21));
        QFont font1;
        font1.setPointSize(14);
        lblIdLabel->setFont(font1);
        lblTitleLabel = new QLabel(taskWindow);
        lblTitleLabel->setObjectName(QStringLiteral("lblTitleLabel"));
        lblTitleLabel->setGeometry(QRect(20, 160, 91, 16));
        lblTitleLabel->setFont(font1);
        lblTextLabel = new QLabel(taskWindow);
        lblTextLabel->setObjectName(QStringLiteral("lblTextLabel"));
        lblTextLabel->setGeometry(QRect(20, 270, 91, 16));
        lblTextLabel->setFont(font1);
        lblIdViewer = new QLabel(taskWindow);
        lblIdViewer->setObjectName(QStringLiteral("lblIdViewer"));
        lblIdViewer->setGeometry(QRect(120, 100, 47, 20));
        lblIdViewer->setFont(font1);
        ledTaskTitle = new QLineEdit(taskWindow);
        ledTaskTitle->setObjectName(QStringLiteral("ledTaskTitle"));
        ledTaskTitle->setGeometry(QRect(20, 190, 601, 41));
        QFont font2;
        font2.setPointSize(18);
        ledTaskTitle->setFont(font2);
        ledTaskTitle->setMaxLength(20);
        tedTaskText = new QTextEdit(taskWindow);
        tedTaskText->setObjectName(QStringLiteral("tedTaskText"));
        tedTaskText->setGeometry(QRect(20, 300, 601, 121));
        QFont font3;
        font3.setPointSize(10);
        tedTaskText->setFont(font3);
        line_2 = new QFrame(taskWindow);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 130, 640, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(taskWindow);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 240, 640, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        bbxButtons = new QDialogButtonBox(taskWindow);
        bbxButtons->setObjectName(QStringLiteral("bbxButtons"));
        bbxButtons->setGeometry(QRect(400, 440, 211, 41));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bbxButtons->sizePolicy().hasHeightForWidth());
        bbxButtons->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setPointSize(13);
        bbxButtons->setFont(font4);
        bbxButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        bbxButtons->setCenterButtons(true);

        retranslateUi(taskWindow);

        QMetaObject::connectSlotsByName(taskWindow);
    } // setupUi

    void retranslateUi(QWidget *taskWindow)
    {
        taskWindow->setWindowTitle(QApplication::translate("taskWindow", "New Task", 0));
        lblWindowLabel->setText(QApplication::translate("taskWindow", "New Task Window", 0));
        lblIdLabel->setText(QApplication::translate("taskWindow", "Task Id:", 0));
        lblTitleLabel->setText(QApplication::translate("taskWindow", "Task Title:", 0));
        lblTextLabel->setText(QApplication::translate("taskWindow", "Task Text:", 0));
        lblIdViewer->setText(QApplication::translate("taskWindow", "...", 0));
        ledTaskTitle->setText(QString());
        ledTaskTitle->setPlaceholderText(QApplication::translate("taskWindow", "Title length: Max 20 characters", 0));
        tedTaskText->setHtml(QApplication::translate("taskWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8.25pt;\"><br /></p></body></html>", 0));
        tedTaskText->setPlaceholderText(QApplication::translate("taskWindow", "Text length: max 140 characters", 0));
    } // retranslateUi

};

namespace Ui {
    class taskWindow: public Ui_taskWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKWINDOW_H
