#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>

//主窗体

namespace Ui {
class window;
}

class window : public QWidget
{
    Q_OBJECT

public:
    explicit window(QWidget *parent = 0);
    ~window();
public slots:
    void setLCD(int);
private slots:
    void changeTextInButton();

private:

    Ui::window *ui;
    int score=0;
};

#endif // WINDOW_H
