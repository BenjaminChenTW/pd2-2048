#include "enterpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EnterPage w;
    w.show();

    return a.exec();
}
