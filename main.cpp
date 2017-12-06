#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setApplicationName(QString(APP_NAME).replace("_", " "));
    qApp->setApplicationVersion(APP_VERSION);
    MainWindow w;
    w.setWindowTitle(qApp->applicationName() + QString(" - ") + qApp->applicationVersion());
    w.show();
    // Debug for opening a file with double click or "open with..."
    /*
    if(argc > 1){

    }
    */
    return a.exec();
}
