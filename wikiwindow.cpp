#include "wikiwindow.hpp"
#include "ui_wikiwindow.h"
#include <QUrl>

WikiWindow::WikiWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::WikiWindow)
{
  ui->setupUi(this);
  QString dirPath;
  dirPath = qApp->applicationDirPath();
  dirPath += "/Wiki Workflow/index.html";
  dirPath = "file:///" + dirPath;
  ui->wikiBrowser->setSource(QUrl(dirPath));
}

WikiWindow::~WikiWindow()
{
  delete ui;
}
