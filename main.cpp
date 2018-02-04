#include "mainwindow.hpp"
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/resources/Ubuntu-R.ttf");
    qApp->setFont(QFont("Ubuntu", 11, QFont::Normal, false));
    qApp->setApplicationName(QString(APP_NAME).replace("_", " "));
    qApp->setApplicationVersion(APP_VERSION);
    QString projPath = "";
    if(argc > 1){
        projPath = QString(argv[1]);
    }
    MainWindow w(projPath);
    w.setWindowTitle(qApp->applicationName() + QString(" - ") + qApp->applicationVersion());
    w.show();
    return a.exec();
}
