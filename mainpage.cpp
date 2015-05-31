#include "mainpage.h"
#include "ui_mainpage.h"
#include <time.h>

MainPage::MainPage(QWidget *parent, int *Win) :
    QWidget(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    srand(time(NULL));
    win=Win;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            blocks[i][j]=new Game(this, i, j);
            ifEmpty[i][j]=true;
        }
    }
    connect(ui->quitInGame,SIGNAL(clicked()),this,SLOT(Quit()));
    connect(ui->backInGame,SIGNAL(clicked()),this,SLOT(Back()));
    firstEvent();
    this->setFocus();
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::dirEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Up:
        if (upEvent())
            addNew();
        break;
    case Qt::Key_Down:
        if (downEvent())
            addNew();
        break;
    case Qt::Key_Left:
        if (leftEvent())
            addNew();
        break;
    case Qt::Key_Right:
        if (rightEvent())
            addNew();
        break;
    default:
        break;
    }
    int ctr=0;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if (blocks[i][j]->getValue() == 11)
                endPage(1);
            if (!ifEmpty[i][j])
                ctr++;
        }
    }
    if (ctr>=16 && ifEnd())
        endPage(2);
}

void MainPage::Quit()
{
    exit(1);
}

void MainPage::Back(){
    this->close();
}

void MainPage::firstEvent(){
    int x = rand() % 4;
    int y1, y2;
    int z = rand() % 2;
    y1 = rand() % 4;
    z? changeValue(x, y1, 1) : changeValue(y1, x, 1);
    do {y2 = rand() % 4;} while(y2 == y1);
    z? changeValue(x, y2, 1) : changeValue(y2, x, 1);
}

void MainPage::changeValue(int X, int Y, int value){
    if (value == 0)
        ifEmpty[X][Y] = true;
    else
        ifEmpty[X][Y] = false;
    blocks[X][Y]->transform(value);
}

void MainPage::addNew(){
    int x, y;
    do{
        x = rand() % 4;
        y = rand() % 4;
    } while(!ifEmpty[x][y]);
    int v = rand() % 4;
    v? v=1:v=2;
    changeValue(x, y, v);
}

void MainPage::endPage(int result)
{
    *win=result;
    this->hide();
}

bool MainPage::ifEnd()
{
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if ((i-1)>0)
                if (blocks[i][j]->getValue() == blocks[i-1][j]->getValue())
                    return false;
            if ((j-1)>0)
                if (blocks[i][j]->getValue() == blocks[i][j-1]->getValue())
                    return false;
            if ((i+1)<4)
                if (blocks[i][j]->getValue() == blocks[i+1][j]->getValue())
                    return false;
            if ((j+1)<4)
                if (blocks[i][j]->getValue() == blocks[i][j+1]->getValue())
                    return false;
        }
    }
    return true;
}

bool MainPage::upEvent(){
    bool move=false;
    for (int i=0; i<4; i++){
        for (int j=3; j>0; j--){
            if (!ifEmpty[i][j]){
                for (int k=j-1; k>=0; k--){
                    if (!ifEmpty[i][k]){
                        if (blocks[i][j]->getValue() == blocks[i][k]->getValue()){
                            for (int t=k-1; t>=0; t--){
                                if (!ifEmpty[i][t]){
                                    if (blocks[i][j]->getValue() == blocks[i][t]->getValue()){
                                        k=t;
                                    }
                                    else break;
                                }
                            }
                            changeValue(i, k, blocks[i][j]->getValue()+1);
                            changeValue(i, j, 0);
                            k-=1;
                            j=k;
                            move=true;
                        }
                        else break;
                    }
                }
            }
            if (j<=0) break;
        }
        for (int j=0; j<4; j++){
            if (!ifEmpty[i][j]){
                for (int k=0; k<j; k++){
                    if (ifEmpty[i][k]){
                        changeValue(i, k, blocks[i][j]->getValue());
                        changeValue(i, j, 0);
                        move=true;
                    }
                }
            }
        }
    }
    return move;
}

bool MainPage::downEvent(){
    bool move=false;
    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            if (!ifEmpty[i][j]){
                for (int k=j+1; k<4; k++){
                    if (!ifEmpty[i][k]){
                        if (blocks[i][j]->getValue() == blocks[i][k]->getValue()){
                            for (int t=k+1; t<4; t++){
                                if (!ifEmpty[i][t]){
                                    if (blocks[i][j]->getValue() == blocks[i][t]->getValue()){
                                        k=t;
                                    }
                                    else break;
                                }
                            }
                            changeValue(i, k, blocks[i][j]->getValue()+1);
                            changeValue(i, j, 0);
                            k+=1;
                            j=k;
                            move=true;
                        }
                        else break;
                    }
                }
            }
            if (j>=4) break;
        }
        for (int j=3; j>=0; j--){
            if (!ifEmpty[i][j]){
                for (int k=3; k>j; k--){
                    if (ifEmpty[i][k]){
                        changeValue(i, k, blocks[i][j]->getValue());
                        changeValue(i, j, 0);
                        move=true;
                    }
                }
            }
        }
    }
    return move;
}

bool MainPage::leftEvent(){
    bool move=false;
    for (int i=0; i<4; i++){
        for (int j=3; j>0; j--){
            if (!ifEmpty[j][i]){
                for (int k=j-1; k>=0; k--){
                    if (!ifEmpty[k][i]){
                        if (blocks[j][i]->getValue() == blocks[k][i]->getValue()){
                            for (int t=k-1; t>=0; t--){
                                if (!ifEmpty[t][i]){
                                    if (blocks[j][i]->getValue() == blocks[t][i]->getValue()){
                                        k=t;
                                    }
                                    else break;
                                }
                            }
                            changeValue(k, i, blocks[j][i]->getValue()+1);
                            changeValue(j, i, 0);
                            k-=1;
                            j=k;
                            move=true;
                        }
                        else break;
                    }
                }
            }
            if (j<=0) break;
        }
        for (int j=0; j<4; j++){
            if (!ifEmpty[j][i]){
                for (int k=0; k<j; k++){
                    if (ifEmpty[k][i]){
                        changeValue(k, i, blocks[j][i]->getValue());
                        changeValue(j, i, 0);
                        move=true;
                    }
                }
            }
        }
    }
    return move;
}

bool MainPage::rightEvent(){
    bool move=false;
    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++){
            if (!ifEmpty[j][i]){
                for (int k=j+1; k<4; k++){
                    if (!ifEmpty[k][i]){
                        if (blocks[j][i]->getValue() == blocks[k][i]->getValue()){
                            for (int t=k+1; t<4; t++){
                                if (!ifEmpty[t][i]){
                                    if (blocks[j][i]->getValue() == blocks[t][i]->getValue()){
                                        k=t;
                                    }
                                    else break;
                                }
                            }
                            changeValue(k, i, blocks[j][i]->getValue()+1);
                            changeValue(j, i, 0);
                            k+=1;
                            j=k;
                            move=true;
                        }
                        else break;
                    }
                }
            }
            if (j>=4) break;
        }
        for (int j=3; j>=0; j--){
            if (!ifEmpty[j][i]){
                for (int k=3; k>j; k--){
                    if (ifEmpty[k][i]){
                        changeValue(k, i, blocks[j][i]->getValue());
                        changeValue(j, i, 0);
                        move=true;
                    }
                }
            }
        }
    }
    return move;
}
