#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QLabel>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent, int X, int Y);
    ~Game();
    void transform(int Value);
    int getValue();
private:
    int x;
    int y;
    int value;
    QLabel *pic;
};

#endif // GAME_H
