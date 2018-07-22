#include "wall.h"


Wall::Wall():Object(POSITION(0,0), WALL_COLOR, true)
{

}

Wall::Wall(POSITION pos, const QColor& color, bool isBlock) :Object(pos, color, isBlock) {
}

Wall::~Wall() {
}

INFO Wall::Execute(const INFO& nowInfo)const {
    INFO tmp(nowInfo);
    tmp.isDead = true;
    return tmp;
}
