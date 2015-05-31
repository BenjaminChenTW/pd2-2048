#include "game.h"

Game::Game(QWidget *parent, int X, int Y)
{
    x=X;
    y=Y;
    value=0;
    pic=new QLabel(parent);
    pic->setGeometry(x*110+25, y*110+185, 100, 100);
    pic->setPixmap(QPixmap(":/images/0"));
}

Game::~Game()
{
    delete pic;
}

void Game::transform(int Value){
    value=Value;
    switch (value) {
    case 0:
        pic->setPixmap(QPixmap(":/images/0"));
        break;
    case 1:
        pic->setPixmap(QPixmap(":/images/icons/1.png"));
        break;
    case 2:
        pic->setPixmap(QPixmap(":/images/icons/2.png"));
        break;
    case 3:
        pic->setPixmap(QPixmap(":/images/icons/3.png"));
        break;
    case 4:
        pic->setPixmap(QPixmap(":/images/icons/4.png"));
        break;
    case 5:
        pic->setPixmap(QPixmap(":/images/icons/5.png"));
        break;
    case 6:
        pic->setPixmap(QPixmap(":/images/icons/6.png"));
        break;
    case 7:
        pic->setPixmap(QPixmap(":/images/icons/7.png"));
        break;
    case 8:
        pic->setPixmap(QPixmap(":/images/icons/8.png"));
        break;
    case 9:
        pic->setPixmap(QPixmap(":/images/icons/9.png"));
        break;
    case 10:
        pic->setPixmap(QPixmap(":/images/icons/10.png"));
        break;
    case 11:
        pic->setPixmap(QPixmap(":/images/icons/11.png"));
        break;
    default:
        break;
    }
}

int Game::getValue(){
    return value;
}
