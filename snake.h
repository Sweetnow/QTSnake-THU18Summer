#ifndef SNAKE_H
#define SNAKE_H

#include"snakepart.h"
#include<list>

#define pSNAKE (Snake::Instance())

enum DIRECTION { _up, _down, _left, _right};

const DIRECTION startDirection = _down; //起始方向

class Snake {
    //单例设计模式
private:
    Snake(){}
    Snake(POSITION startPos,DIRECTION startDirection);
    Snake(const Snake& _right){}
public:
    virtual ~Snake();
    static Snake* Instance(){
        static Snake instance(POSITION(MAP_X/2,MAP_Y/2),startDirection);
        return &instance;
    }
    //Get
    const std::list<SnakePart>& GetSnake()const;
    //加长蛇身长度
    void CreateBody();
    //eDirection为接下来的前进方向
    POSITION ReadyMove(DIRECTION eDirection);
    void Move();
    //初始化
    void Init();
private:
    std::list<SnakePart>m_Snake;
    DIRECTION m_eDirection;
};

DIRECTION OppositeDirection(DIRECTION eDirection);
#endif // SNAKE_H
