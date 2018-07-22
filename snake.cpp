#include "snake.h"


DIRECTION OppositeDirection(DIRECTION eDirection) {
    switch (eDirection) {
    case _up:return _down; break;
    case _down:return _up; break;
    case _left:return _right; break;
    case _right:return _left; break;
    }
    return _down;
}

const std::list<SnakePart>& Snake::GetSnake() const {
    return m_Snake;
}

Snake::Snake(POSITION startPos, DIRECTION startDirection) :m_eDirection(startDirection) {
    SnakePart head(startPos, true);
    m_Snake.push_back(head);
}

Snake::~Snake() {
}


POSITION Snake::ReadyMove(DIRECTION eDirection) {
     SnakePart newhead(m_Snake.front());
    //确定前进方向
    if (eDirection != OppositeDirection(m_eDirection))
        m_eDirection = eDirection;
    switch (m_eDirection) {
    case _up:
        newhead.m_Pos.x--;
        break;
    case _down:
        newhead.m_Pos.x++;
        break;
    case _left:
        newhead.m_Pos.y--;
        break;
    case _right:
        newhead.m_Pos.y++;
        break;
    }   
    return newhead.GetPosition();
}

void Snake::Move()
{
    SnakePart newhead(m_Snake.front());
    switch (m_eDirection) {
    case _up:
        newhead.m_Pos.x--;
        break;
    case _down:
        newhead.m_Pos.x++;
        break;
    case _left:
        newhead.m_Pos.y--;
        break;
    case _right:
        newhead.m_Pos.y++;
        break;
    }
    m_Snake.front().SetIsHead(false);
    m_Snake.push_front(newhead);
    m_Snake.pop_back();
    return;
}



void Snake::CreateBody() {
    SnakePart newbody(m_Snake.back());
    newbody.SetIsHead(false);
    m_Snake.push_back(newbody);
}

void Snake::Init()
{
    m_Snake.clear();
    SnakePart head(POSITION(MAP_X/2,MAP_Y/2), true);
    m_Snake.push_back(head);
    m_eDirection=startDirection;
}
