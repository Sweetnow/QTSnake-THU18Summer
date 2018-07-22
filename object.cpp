#include "object.h"

Object::Object() {
}

Object::Object(POSITION pos, const QColor& color, bool isBlock) :m_Pos(pos), m_eColor(color), m_isBlock(isBlock) {
}

Object::~Object() {
}

POSITION Object::GetPosition() const {
    return m_Pos;
}


bool Object::IsBlock() const {
    return m_isBlock;
}

void Object::SetPosition(POSITION pos) {
    m_Pos = pos;
}


void Object::SetIsBlock(bool isBlock) {
    m_isBlock = isBlock;
}

QColor Object::GetColor() const
{
    return m_eColor;
}

void Object::setEColor(const QColor&eColor)
{
    m_eColor = eColor;
}

bool operator ==(const POSITION &left, const POSITION &right)
{
    return left.x==right.x && left.y==right.y;
}

bool operator !=(const POSITION &left, const POSITION &right)
{
    return !(left==right);
}
