#ifndef OBJECT_H
#define OBJECT_H


#include<cstdlib>
#include<cassert>
#include<QColor>

//地图情况
const int MAP_X=50;
const int MAP_Y=50;

//坐标结构体
struct POSITION {
    int x;
    int y;
    POSITION() {}
    POSITION(int x, int y) :x(x), y(y) {}
};
bool operator ==(const POSITION&,const POSITION&);
bool operator !=(const POSITION&,const POSITION&);

//全局游戏信息
struct INFO {
    int score;   //得分
    bool isDead;   //蛇是否死亡
    int hard;   //目前难度(对应蛇移动速度)
    bool isEat;    //是否吃食
    INFO() {}
    INFO(int score, bool isDead, int hard, bool isEat) :
        score(score), isDead(isDead), hard(hard), isEat(isEat) {
    }
};

//定义基础对象
class Object {
public:
    Object();
    Object(POSITION, const QColor&, bool);
    virtual ~Object();

    //Get

    POSITION GetPosition()const;
    bool IsBlock()const;
    QColor GetColor() const;

    //Set
    void SetPosition(POSITION);
    void SetIsBlock(bool);
    void setEColor(const QColor&eColor);

    //被蛇接触后触发的行为
    virtual INFO Execute(const INFO&)const = 0;


protected:
    POSITION m_Pos;    //坐标
    QColor m_eColor;    //显示颜色
    bool m_isBlock;    //蛇可通过为false

};

#endif // OBJECT_H
