#include "Food.h"

Food::Food(QObject *parent) : QObject(parent)
{

}

int Food::foodWidth() const{
    return m_foodWidth;
}
void Food::setFoodWidth(int x){
    if(m_foodWidth!=x){
        m_foodWidth = x;
        emit foodWidthChanged(x);
    }
}
int Food::foodHeight() const{
    return m_foodHeight;
}
void Food::setFoodHeight(int x){
    if(m_foodHeight!=x){
        m_foodHeight = x;
        emit foodHeightChanged(x);
    }
}


int Food::foodx() const{
    qDebug() << " get foodx :" << m_foodx << " --foody :" << m_foody;
    return m_foodx;
}
void Food::setFoodx(int x){
    qDebug() << " set foodx :" <<x << "--"<<  m_foodx << " -++foody :" << m_foody;
    if(m_foodx!=x){
        m_foodx = x;
        emit foodxChanged(x);
    }
}

int Food::foody() const{
    return m_foody;
}
void Food::setFoody(int y){
    if(m_foody!=y){
        m_foody = y;
        emit foodyChanged(y);
    }
}

Coordinate* Food::foodPostion() const{
    return m_food;
}
void Food::setFoodPostion(Coordinate* food){
    if(m_food!=food){
        m_food = food;
        emit foodPostionChanged();
    }
}

void Food::changePosition(int x,int y){
    if(m_food){
        m_food->setXKoordinate(x);
        m_food->setYKoordinate(y);
        emit foodPostionChanged();
    }
}
