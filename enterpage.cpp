#include "enterpage.h"
#include "ui_enterpage.h"

EnterPage::EnterPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EnterPage)
{
    ui->setupUi(this);
    connect(ui->start,SIGNAL(clicked()),this,SLOT(ClickStart()));
    connect(ui->quit,SIGNAL(clicked()),this,SLOT(ClickQuit()));
    game=NULL;
}

EnterPage::~EnterPage()
{
    delete ui;
}

void EnterPage::ClickStart()
{
    win = new int(0);
    game = new MainPage(this, win);
    //ui->start->isHidden();
    this->setCentralWidget(game);
}

void EnterPage::ClickQuit()
{
    this->close();
}

void EnterPage::keyPressEvent(QKeyEvent *event){
    //qDebug() << event->text();
    if (game != NULL) {
        game->dirEvent(event);
    }
    switch (*win) {
    case 0:
        ui->result->setText("");
        break;
    case 1:
        ui->result->setText("You Win");
        break;
    case 2:
        ui->result->setText("You Lose");
        break;
    default:
        break;
    }
}
