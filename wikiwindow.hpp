#ifndef WIKIWINDOW_HPP
#define WIKIWINDOW_HPP

#include <QWidget>

namespace Ui {
  class WikiWindow;
}

class WikiWindow : public QWidget
{
  Q_OBJECT

public:
  explicit WikiWindow(QWidget *parent = 0);
  ~WikiWindow();

private:
  Ui::WikiWindow *ui;
};

#endif // WIKIWINDOW_HPP
