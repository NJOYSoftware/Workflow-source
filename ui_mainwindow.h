/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionReport_Bug;
    QAction *actionNew_Project;
    QAction *actionHelp;
    QAction *actionModify_Project_Title;
    QAction *actionAbout_Qt;
    QAction *actionAbout_Workflow;
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *lblProjectTitle;
    QLabel *lblDepTree;
    QGroupBox *gbxCurrentNode;
    QGraphicsView *grvCurrentTask;
    QFrame *line;
    QGroupBox *gbxCurrentText;
    QLabel *lblCurrentTitle;
    QTextEdit *tedCurrentText;
    QPushButton *btnModify;
    QPushButton *btnComplete;
    QPushButton *btnAddChild;
    QLabel *lblChildren;
    QPushButton *btnPrevTask;
    QGraphicsView *grvChild1;
    QGraphicsView *grvChild2;
    QGraphicsView *grvChild3;
    QGraphicsView *grvChild4;
    QPushButton *btnNewMaster;
    QPushButton *btnPreviousPage;
    QPushButton *btnNextPage;
    QLabel *lblChildrenPage;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(982, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(982, 600));
        MainWindow->setMouseTracking(true);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Desktop/Workflow Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionLoad->setShortcutContext(Qt::WidgetShortcut);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionReport_Bug = new QAction(MainWindow);
        actionReport_Bug->setObjectName(QStringLiteral("actionReport_Bug"));
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QStringLiteral("actionNew_Project"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionModify_Project_Title = new QAction(MainWindow);
        actionModify_Project_Title->setObjectName(QStringLiteral("actionModify_Project_Title"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionAbout_Workflow = new QAction(MainWindow);
        actionAbout_Workflow->setObjectName(QStringLiteral("actionAbout_Workflow"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 984, 41));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(3);
        lblProjectTitle = new QLabel(frame);
        lblProjectTitle->setObjectName(QStringLiteral("lblProjectTitle"));
        lblProjectTitle->setGeometry(QRect(10, 0, 951, 31));
        QFont font;
        font.setPointSize(21);
        lblProjectTitle->setFont(font);
        lblDepTree = new QLabel(centralWidget);
        lblDepTree->setObjectName(QStringLiteral("lblDepTree"));
        lblDepTree->setGeometry(QRect(8, 45, 961, 30));
        QFont font1;
        font1.setPointSize(16);
        lblDepTree->setFont(font1);
        gbxCurrentNode = new QGroupBox(centralWidget);
        gbxCurrentNode->setObjectName(QStringLiteral("gbxCurrentNode"));
        gbxCurrentNode->setGeometry(QRect(0, 110, 391, 261));
        grvCurrentTask = new QGraphicsView(gbxCurrentNode);
        grvCurrentTask->setObjectName(QStringLiteral("grvCurrentTask"));
        grvCurrentTask->setGeometry(QRect(15, 20, 360, 216));
        grvCurrentTask->setMouseTracking(false);
        grvCurrentTask->setAcceptDrops(false);
        grvCurrentTask->setAutoFillBackground(false);
        grvCurrentTask->setFrameShape(QFrame::StyledPanel);
        grvCurrentTask->setFrameShadow(QFrame::Plain);
        grvCurrentTask->setLineWidth(1);
        grvCurrentTask->setMidLineWidth(0);
        grvCurrentTask->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvCurrentTask->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        grvCurrentTask->setBackgroundBrush(brush);
        grvCurrentTask->setInteractive(false);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(380, 110, 20, 261));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        gbxCurrentText = new QGroupBox(centralWidget);
        gbxCurrentText->setObjectName(QStringLiteral("gbxCurrentText"));
        gbxCurrentText->setGeometry(QRect(392, 110, 591, 261));
        lblCurrentTitle = new QLabel(gbxCurrentText);
        lblCurrentTitle->setObjectName(QStringLiteral("lblCurrentTitle"));
        lblCurrentTitle->setGeometry(QRect(10, 10, 571, 31));
        QFont font2;
        font2.setPointSize(18);
        lblCurrentTitle->setFont(font2);
        lblCurrentTitle->setAlignment(Qt::AlignCenter);
        tedCurrentText = new QTextEdit(gbxCurrentText);
        tedCurrentText->setObjectName(QStringLiteral("tedCurrentText"));
        tedCurrentText->setEnabled(true);
        tedCurrentText->setGeometry(QRect(10, 50, 571, 161));
        QFont font3;
        font3.setPointSize(14);
        tedCurrentText->setFont(font3);
        tedCurrentText->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        tedCurrentText->setStyleSheet(QStringLiteral("background-color: rgb(240, 240, 240);"));
        tedCurrentText->setFrameShape(QFrame::NoFrame);
        tedCurrentText->setFrameShadow(QFrame::Plain);
        tedCurrentText->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        btnModify = new QPushButton(gbxCurrentText);
        btnModify->setObjectName(QStringLiteral("btnModify"));
        btnModify->setEnabled(false);
        btnModify->setGeometry(QRect(10, 220, 121, 31));
        btnComplete = new QPushButton(gbxCurrentText);
        btnComplete->setObjectName(QStringLiteral("btnComplete"));
        btnComplete->setEnabled(false);
        btnComplete->setGeometry(QRect(460, 220, 121, 31));
        btnAddChild = new QPushButton(gbxCurrentText);
        btnAddChild->setObjectName(QStringLiteral("btnAddChild"));
        btnAddChild->setEnabled(false);
        btnAddChild->setGeometry(QRect(230, 220, 141, 31));
        lblChildren = new QLabel(centralWidget);
        lblChildren->setObjectName(QStringLiteral("lblChildren"));
        lblChildren->setGeometry(QRect(390, 380, 211, 31));
        lblChildren->setFont(font2);
        lblChildren->setAlignment(Qt::AlignCenter);
        btnPrevTask = new QPushButton(centralWidget);
        btnPrevTask->setObjectName(QStringLiteral("btnPrevTask"));
        btnPrevTask->setEnabled(false);
        btnPrevTask->setGeometry(QRect(10, 80, 121, 23));
        grvChild1 = new QGraphicsView(centralWidget);
        grvChild1->setObjectName(QStringLiteral("grvChild1"));
        grvChild1->setGeometry(QRect(3, 420, 240, 144));
        grvChild1->setMouseTracking(true);
        grvChild1->setAutoFillBackground(false);
        grvChild1->setFrameShape(QFrame::StyledPanel);
        grvChild1->setFrameShadow(QFrame::Plain);
        grvChild1->setLineWidth(1);
        grvChild1->setMidLineWidth(0);
        grvChild1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvChild1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvChild1->setBackgroundBrush(brush);
        grvChild2 = new QGraphicsView(centralWidget);
        grvChild2->setObjectName(QStringLiteral("grvChild2"));
        grvChild2->setGeometry(QRect(249, 420, 240, 144));
        grvChild2->setMouseTracking(true);
        grvChild2->setAutoFillBackground(false);
        grvChild2->setFrameShape(QFrame::StyledPanel);
        grvChild2->setFrameShadow(QFrame::Plain);
        grvChild2->setLineWidth(1);
        grvChild2->setMidLineWidth(0);
        grvChild2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvChild2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvChild2->setBackgroundBrush(brush);
        grvChild3 = new QGraphicsView(centralWidget);
        grvChild3->setObjectName(QStringLiteral("grvChild3"));
        grvChild3->setGeometry(QRect(494, 420, 240, 144));
        grvChild3->setMouseTracking(true);
        grvChild3->setAutoFillBackground(false);
        grvChild3->setFrameShape(QFrame::StyledPanel);
        grvChild3->setFrameShadow(QFrame::Plain);
        grvChild3->setLineWidth(1);
        grvChild3->setMidLineWidth(0);
        grvChild3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvChild3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvChild3->setBackgroundBrush(brush);
        grvChild4 = new QGraphicsView(centralWidget);
        grvChild4->setObjectName(QStringLiteral("grvChild4"));
        grvChild4->setGeometry(QRect(739, 420, 240, 144));
        grvChild4->setMouseTracking(true);
        grvChild4->setAutoFillBackground(false);
        grvChild4->setFrameShape(QFrame::StyledPanel);
        grvChild4->setFrameShadow(QFrame::Plain);
        grvChild4->setLineWidth(1);
        grvChild4->setMidLineWidth(0);
        grvChild4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvChild4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        grvChild4->setBackgroundBrush(brush);
        btnNewMaster = new QPushButton(centralWidget);
        btnNewMaster->setObjectName(QStringLiteral("btnNewMaster"));
        btnNewMaster->setEnabled(false);
        btnNewMaster->setGeometry(QRect(820, 80, 161, 25));
        btnPreviousPage = new QPushButton(centralWidget);
        btnPreviousPage->setObjectName(QStringLiteral("btnPreviousPage"));
        btnPreviousPage->setEnabled(false);
        btnPreviousPage->setGeometry(QRect(0, 390, 41, 20));
        btnNextPage = new QPushButton(centralWidget);
        btnNextPage->setObjectName(QStringLiteral("btnNextPage"));
        btnNextPage->setEnabled(false);
        btnNextPage->setGeometry(QRect(930, 390, 41, 23));
        lblChildrenPage = new QLabel(centralWidget);
        lblChildrenPage->setObjectName(QStringLiteral("lblChildrenPage"));
        lblChildrenPage->setGeometry(QRect(570, 380, 141, 31));
        lblChildrenPage->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 982, 27));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuMenu->addAction(actionNew_Project);
        menuMenu->addSeparator();
        menuMenu->addAction(actionModify_Project_Title);
        menuMenu->addSeparator();
        menuMenu->addAction(actionSave);
        menuMenu->addAction(actionLoad);
        menuAbout->addAction(actionHelp);
        menuAbout->addSeparator();
        menuAbout->addAction(actionReport_Bug);
        menuAbout->addSeparator();
        menuAbout->addAction(actionAbout_Workflow);
        menuAbout->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Workflow", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionReport_Bug->setText(QApplication::translate("MainWindow", "Report Bug", 0));
        actionNew_Project->setText(QApplication::translate("MainWindow", "New Project...", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        actionModify_Project_Title->setText(QApplication::translate("MainWindow", "Modify Project Title", 0));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionAbout_Workflow->setText(QApplication::translate("MainWindow", "About Workflow", 0));
        lblProjectTitle->setText(QString());
        lblDepTree->setText(QString());
        gbxCurrentNode->setTitle(QString());
        gbxCurrentText->setTitle(QString());
        lblCurrentTitle->setText(QString());
        tedCurrentText->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", 0));
        btnModify->setText(QApplication::translate("MainWindow", "Modify Task", 0));
        btnComplete->setText(QApplication::translate("MainWindow", "Complete Task", 0));
        btnAddChild->setText(QApplication::translate("MainWindow", "Add Sub Task", 0));
        lblChildren->setText(QApplication::translate("MainWindow", "Sub Tasks", 0));
        btnPrevTask->setText(QApplication::translate("MainWindow", "Previous Task", 0));
        btnNewMaster->setText(QApplication::translate("MainWindow", "New Super Task", 0));
        btnPreviousPage->setText(QApplication::translate("MainWindow", "<", 0));
        btnNextPage->setText(QApplication::translate("MainWindow", ">", 0));
        lblChildrenPage->setText(QApplication::translate("MainWindow", "Page:", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H