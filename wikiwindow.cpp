#include "wikiwindow.hpp"
#include "ui_wikiwindow.h"
#include <QUrl>

WikiWindow::WikiWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::WikiWindow)
{
  ui->setupUi(this);

  ui->wikiBrowser->setSource(QUrl(":/Wiki"));
}

WikiWindow::~WikiWindow()
{
  delete ui;
}
