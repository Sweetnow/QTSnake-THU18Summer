#include "snakepart.h"


SnakePart::SnakePart(POSITION pos, bool isHead, bool isBlock) :m_isHead(isHead) {
    m_Pos = pos;
    m_isBlock = isBlock;
    if (isHead)
        m_eColor = HEAD_COLOR;
    else
        m_eColor = BODY_COLOR;
}

SnakePart::~SnakePart() {
}

bool SnakePart::IsHead() const {
    return m_isHead;
}

void SnakePart::SetIsHead(bool isHead) {
    m_isHead = isHead;
    if(!m_isHead)
        m_eColor=BODY_COLOR;
}

INFO SnakePart::Execute(const INFO & nowInfo)const {
    INFO tmp(nowInfo);
    tmp.isDead = true;
    return tmp;
}
