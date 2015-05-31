#include "enterpage.h"
#include "ui_enterpage.h"

EnterPage::EnterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnterPage)
{
    ui->setupUi(this);
}

EnterPage::~EnterPage()
{
    delete ui;
}
