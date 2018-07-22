#include "window.h"
#include "ui_window.h"


window::window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window)
{
    ui->setupUi(this);
}

window::~window()
{
    delete ui;
}

void window::setLCD(int score)
{
    ui->lcdNumber->display(score);
}

void window::changeTextInButton()
{
    ui->pushButton->setText(tr("重新开始"));
}
