#ifndef FOOD_H
#define FOOD_H

#include "object.h"

const int FOOD_BASE = 6;    //最低难度食物数

const QColor FOOD_COLOR=QColor(255,0,0,255);    //食物是红色

class Food :
    public Object {
public:
    Food();
    Food(POSITION pos, const QColor& color= FOOD_COLOR, bool isBlock = false, int scoreInc = 1);
    virtual ~Food();

    //Get

    int GetScoreInc()const;

    //Set
    void SetScoreInc(int);

    //基类函数实现
    virtual INFO Execute(const INFO&)const;
    bool GetIsEat() const;

    void SetIsEat(bool value);

protected:
    int m_scoreInc;   //吃一个食物增加的基础得分
    mutable bool isEat;    //true 代表被吃了或未初始化
};


#endif // FOOD_H
