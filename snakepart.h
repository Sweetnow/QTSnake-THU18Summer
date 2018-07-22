#ifndef SNAKEPART_H
#define SNAKEPART_H

#include "object.h"

const QColor HEAD_COLOR=QColor(172,172,0);
const QColor BODY_COLOR=QColor(224,224,0);

class SnakePart :
    public Object {
public:

    SnakePart(POSITION pos, bool isHead, bool isBlock = true);
    virtual ~SnakePart();
    friend class Snake;
    //Get

    bool IsHead()const;

    //set

    void SetIsHead(bool);

    //基类函数实现
    virtual INFO Execute(const INFO&)const;
protected:
    bool m_isHead;    //若为蛇头为true
};

#endif // SNAKEPART_H
