#include "food.h"

Food::Food():Object(POSITION(0,0),FOOD_COLOR,false),isEat(true),m_scoreInc(1)
{

}

Food::Food(POSITION pos, const QColor& color, bool isBlock, int scoreInc) :
    Object(pos, color, isBlock), m_scoreInc(scoreInc),isEat(true){
}

Food::~Food() {
}

int Food::GetScoreInc() const {
    return m_scoreInc;
}

void Food::SetScoreInc(int scoreInc) {
    m_scoreInc = scoreInc;
}


INFO Food::Execute(const INFO& nowInfo)const {
    INFO tmp(nowInfo);
    tmp.score += m_scoreInc*(nowInfo.hard+1);
    tmp.isEat=true;
    isEat=true;
    return tmp;
}

bool Food::GetIsEat() const
{
    return isEat;
}

void Food::SetIsEat(bool value)
{
    isEat = value;
}
