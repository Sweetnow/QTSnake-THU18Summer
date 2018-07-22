#include "showwidget.h"
#include "ui_showwidget.h"


showWidget::showWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWidget),
    otherWall(nullptr),foodList(nullptr),isFirst(true),isInit(false),barrier(nullptr),timer(nullptr),Mode(1)
{
    ui->setupUi(this);

}

showWidget::~showWidget()
{
    delete[] barrier;
    delete ui;
    if(otherWall!=nullptr){
        delete[] otherWall;
        otherWall=nullptr;
    }
    if(foodList!=nullptr){
        delete[] foodList;
        foodList=nullptr;
    }
}


//键盘事件
void showWidget::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Up: case Qt::Key_W:
        keyDirection=_up;
        break;
    case Qt::Key_Down: case Qt::Key_S:
        keyDirection=_down;
        break;
    case Qt::Key_Left:case Qt::Key_A:
        keyDirection=_left;
        break;
    case Qt::Key_Right:case Qt::Key_D:
        keyDirection=_right;
        break;
    default:
        break;
    }
}

//定时器,触发后
void showWidget::timerUpdate(){
    POSITION tmpPos=pSNAKE->ReadyMove(keyDirection);
    for(auto it=pGAMEMAP->m_vObj.begin();it!=pGAMEMAP->m_vObj.end();it++){
        if((*it)->GetPosition()==tmpPos){
            pGAMEMAP->nowInfo=(*it)->Execute(pGAMEMAP->nowInfo);
            if(pGAMEMAP->nowInfo.isEat)
                pGAMEMAP->m_vObj.erase(it);
            break;
        }
    }
    if(pGAMEMAP->nowInfo.isDead){
        QMessageBox::about(this,tr("游戏结束"),QString("你的得分是:%1").arg(pGAMEMAP->nowInfo.score));
        timer->stop();
    }
    else if(pGAMEMAP->nowInfo.isEat){
        pSNAKE->CreateBody();
        pGAMEMAP->nowInfo.isEat=false;
        setLCD(pGAMEMAP->nowInfo.score);
    }
    createMap();
    update();

}

void showWidget::setMode()
{
    Mode=1;
}

void showWidget::setMode_2()
{
    Mode=2;
}

void showWidget::setMode_3()
{
    Mode=3;
}

void showWidget::setMode_4()
{
    Mode=4;
}

void showWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRectF rectangle = QRectF(-1,-1,this->width()+3,this->height()+3);
    painter.setPen(QPen(QColor(Qt::black)));
    painter.setBrush(QBrush(QColor(Qt::white)));
    painter.drawRect(rectangle);
    QPen pen;
    pen.setWidth(10);
    painter.setPen(pen);
    //test
    if(isInit){
        for(auto it=pGAMEMAP->m_vObj.begin();it!=pGAMEMAP->m_vObj.end();it++){
            pen.setColor((*it)->GetColor());
            painter.setPen(pen);
            painter.drawPoint((*it)->GetPosition().y*10+5,(*it)->GetPosition().x*10+5);
        }
    }
    else{

    }

}

void showWidget::startGame()
{
    //初始化

    this->setFocus();
    keyDirection=_down;
    isFirst=true;
    isInit=false;
    if(barrier!=nullptr){
        delete[] barrier;
        barrier=nullptr;
    }
    if(otherWall!=nullptr){
        delete[] otherWall;
        otherWall=nullptr;
    }
    if(foodList!=nullptr){
        delete[] foodList;
        foodList=nullptr;
    }
    pSNAKE->Init();
    pGAMEMAP->Init();
    pGAMEMAP->nowInfo.hard=(Mode<=3?Mode-1:1);
    emit setLCD(0);
    if(timer!=nullptr){
        delete timer;
        timer=nullptr;
    }
    timer=new QTimer(this);
    timer->setInterval(TIME_BASE/(pGAMEMAP->nowInfo.hard+1));
    connect(timer,SIGNAL(timeout()),SLOT(timerUpdate()));
    timer->start();
    createMap();
    isInit=true;
    update();
}


void showWidget::createMap()
{
    pSNAKE->Move();
    pGAMEMAP->ClearSnake();
    if(isFirst){

        barrierLen=2*(MAP_X+MAP_Y-2);
        //添加围墙
        barrier=new Wall[barrierLen];
        int count=0;
        for(int i=0;i<MAP_Y;i++){
            barrier[count++].SetPosition(POSITION(0,i));
            barrier[count++].SetPosition(POSITION(MAP_X-1,i));
        }
        for(int i=1;i<MAP_X-1;i++){
            barrier[count++].SetPosition(POSITION(i,0));
            barrier[count++].SetPosition(POSITION(i,MAP_Y-1));
        }
        //添加其他障碍物
        //位置由计时器中的逻辑处理
        if(Mode==4)
            otherWallLen=0;
        else{
            otherWallLen=OTHER_WALL_BASE*(int)(exp(pGAMEMAP->nowInfo.hard));
            otherWall=new Wall[otherWallLen];
        }
        //添加食物
        //食物生成由计时器事件中的逻辑处理
        if(Mode==4)
            foodListLen=100;
        else
            foodListLen=(FOOD_BASE/(pGAMEMAP->nowInfo.hard+1)>0?FOOD_BASE/(pGAMEMAP->nowInfo.hard+1):1);
        foodList=new Food[foodListLen];

        for(int i=0;i<barrierLen;i++){
            pGAMEMAP->_Object2Map(barrier[i]);
        }
        //生成随机障碍物
        for(int i=0;i<otherWallLen;i++){
            do{
                int x=qrand()%(MAP_X-4)+2;
                int y=qrand()%(MAP_Y-4)+2;
                otherWall[i].SetPosition(POSITION(x,y));
            }while(!pGAMEMAP->Object2Map(otherWall[i]));
        }
        isFirst=false;
    }
    pGAMEMAP->Snake2Map(*pSNAKE);
    for(int i=0;i<foodListLen;i++){
        if(foodList[i].GetIsEat()){
            //生成随机食物
            do{
                int x=qrand()%(MAP_X-2)+1;
                int y=qrand()%(MAP_Y-2)+1;
                foodList[i].SetPosition(POSITION(x,y));
            }while(!pGAMEMAP->Object2Map(foodList[i]));
            foodList[i].SetIsEat(false);
        }
    }

}
