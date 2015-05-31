#ifndef ENTERPAGE_H
#define ENTERPAGE_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>
#include "mainpage.h"

namespace Ui {
class EnterPage;
}

class EnterPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit EnterPage(QWidget *parent = 0);
    ~EnterPage();
    void endPage(bool *result);

private slots:
    void ClickStart();
    void ClickQuit();

private:
    Ui::EnterPage *ui;
    MainPage *game;
    int *win;
    void keyPressEvent(QKeyEvent *event);
};

#endif // ENTERPAGE_H
