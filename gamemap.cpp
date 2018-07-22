#include "gamemap.h"

Gamemap::Gamemap() {
    m_vObj.reserve((MAP_X+MAP_Y)*4);
    nowInfo = INFO(0,false,0,false);
}

bool Gamemap::Object2Map(const Wall &wall) {
    //墙所在位置周围是否被占用
    for(auto it=m_vObj.begin();it!=m_vObj.end();it++){
        if(abs(wall.GetPosition().x-(*it)->GetPosition().x)<=1 && abs(wall.GetPosition().y-(*it)->GetPosition().y)<=1)    //如果位置相近
            return false;
        if(abs(wall.GetPosition().x-pSNAKE->GetSnake().front().GetPosition().x)<=3 && abs(wall.GetPosition().y-pSNAKE->GetSnake().front().GetPosition().y)<=5)   //蛇的周围不能有障碍物
            return false;
    }
    _Object2Map(wall);
    return true;
}

void Gamemap::_Object2Map(const Object &thing) {
    assert(thing.GetPosition().x>=0&&thing.GetPosition().x<MAP_X&&thing.GetPosition().y>=0&&thing.GetPosition().y<MAP_Y);
    m_vObj.push_back(&thing);
}

bool Gamemap::Object2Map(const Food &food) {
    //食物所在位置是否被占用
    for(auto it=m_vObj.begin();it!=m_vObj.end();it++){
        if(food.GetPosition()==(*it)->GetPosition())    //如果位置重叠
            return false;
    }
    _Object2Map(food);
    return true;
}


void Gamemap::Snake2Map(const Snake &snake) {
    for(auto it=snake.GetSnake().begin();it!=snake.GetSnake().end();it++){
        _Object2Map(*it);
    }
}

void Gamemap::ClearSnake() {
    for(auto it=m_vObj.begin();it!=m_vObj.end();){
        if((*it)->GetColor()==HEAD_COLOR||(*it)->GetColor()==BODY_COLOR)
            it=m_vObj.erase(it);
        else
            it++;
    }
}

void Gamemap::Init()
{
    m_vObj.clear();
    nowInfo=INFO(0,false,0,false);
}

