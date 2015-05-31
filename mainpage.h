#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QKeyEvent>
#include "game.h"

namespace Ui {
class MainPage;
}

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent, int *Win);
    ~MainPage();
    void dirEvent(QKeyEvent *event);

private slots:
    void Quit();
    void Back();

private:
    Ui::MainPage *ui;
    void firstEvent();
    void changeValue(int X, int Y, int value);
    void addNew();
    void endPage(int result);
    bool ifEnd();
    bool upEvent();
    bool downEvent();
    bool leftEvent();
    bool rightEvent();
    Game *blocks[4][4];
    bool ifEmpty[4][4];
    int *win;
};

#endif // MAINPAGE_H
