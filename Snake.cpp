#include "Snake.h"
#include "MessageMgr.h"

Snake::Snake(MessageMgr* parent) : QObject(parent)
{

}
Snake::~Snake(){

}

int Snake::snakeWidth() const{
    return m_snakeWidth;
}
void Snake::setSnakeWidth(int w){
    if(m_snakeWidth!=w){
        m_snakeWidth = w;
        emit snakeWidthChanged(w);
    }
}

int Snake::snakeHeight() const{
    return m_snakeHeight;
}
void Snake::setSnakeHeight(int h){
    if(m_snakeHeight!=h){
        m_snakeHeight = h;
        emit snakeHeightChanged(h);
    }
}


int Snake::moveDirection() const{
    return m_moveDirection;
}
void Snake::setMoveDirection(int moveDirection){
    if(m_moveDirection!=moveDirection){
        m_moveDirection = moveDirection;
        emit moveDirectionChanged(moveDirection);
    }
}
int Snake::headx() const{
    return m_headx;
}
void Snake::setHeadx(int x){
    if(m_headx!=x){
        m_headx = x;
        emit headxChanged(x);
    }
}
int Snake::heady() const{
    return m_heady;
}
void Snake::setHeady(int y){
    if(m_heady!=y){
        m_heady = y;
        emit headyChanged(y);
    }
}
