#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>
#include "gamemap.h"
#include <cmath>
#include <QPaintDevice>
#include <QPainter>
#include <QRectF>

//游戏显示窗体

namespace Ui {
class showWidget;
}

class showWidget : public QWidget
{
    Q_OBJECT

public:
    explicit showWidget(QWidget *parent = nullptr);
    ~showWidget();

    void keyPressEvent(QKeyEvent *);

    void paintEvent(QPaintEvent *event);
signals:
    void setLCD(int score);

public slots:
    void startGame();
    void timerUpdate();
    //按钮组
    void setMode();
    void setMode_2();
    void setMode_3();
    void setMode_4();
private:
    void createMap();
    Ui::showWidget *ui;
   //int timer;    //定时器
    DIRECTION keyDirection;    //接受键盘事件
    bool isFirst;
    Wall *barrier;    //围栏
    int barrierLen;    //围栏数组长度
    Wall *otherWall;    //其他障碍物
    int otherWallLen;    //其他障碍物数组长度
    Food *foodList;    //食物
    int foodListLen;    //食物数组长度
    bool isInit;
    QTimer* timer;
    int Mode;
};

#endif // SHOWWIDGET_H
