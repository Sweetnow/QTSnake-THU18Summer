#ifndef WALL_H
#define WALL_H

#include"object.h"

const int OTHER_WALL_BASE = 20;  //除最外层外中间多余的障碍物最低难度下个数

const QColor WALL_COLOR=QColor(0,0,0);

//墙类
class Wall :
    public Object {
public:
    Wall();
    Wall(POSITION pos, const QColor& color= WALL_COLOR, bool isBlock = true);
    virtual ~Wall();

    //基类函数实现
    virtual INFO Execute(const INFO&)const;
};


#endif // WALL_H
