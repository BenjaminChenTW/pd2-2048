#ifndef ENTERPAGE_H
#define ENTERPAGE_H

#include <QWidget>

namespace Ui {
class EnterPage;
}

class EnterPage : public QWidget
{
    Q_OBJECT

public:
    explicit EnterPage(QWidget *parent = 0);
    ~EnterPage();

private:
    Ui::EnterPage *ui;
};

#endif // ENTERPAGE_H
