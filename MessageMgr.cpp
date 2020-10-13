#include "MessageMgr.h"
#include <iostream>
#include <random>
#include <QDebug>

MessageMgr::MessageMgr(QObject *parent) : QObject(parent)
{
    srand(time(NULL));
    std::cout<<"termcolor::red<<x<<termcolor::reset"<<std::endl;
    if (varTimer != nullptr)
        varTimer->stop();
    started=true;

    m_snake = new Snake(this);
    m_snake->setMoveDirection(0);
    m_snake->setSnakeWidth(20);
    m_snake->setSnakeHeight(20);

    int hx= rand()%(500) + 0;
    int hy = rand()%(500) + 0;

    m_snake->setHeadx(hx);
    m_snake->setHeady(hy);

    m_food = new Food(this);
    m_food->setFoodWidth(20);
    m_food->setFoodHeight(20);
    generateFood();
    varTimer = new QTimer(this);
    connect(varTimer, SIGNAL(timeout()), this, SLOT(runSnakeTimer()));

}
MessageMgr::~MessageMgr(){

}

void MessageMgr::generateFood(){

    int hx= rand()%(m_areaX) + 0;
    int hy = rand()%(m_areaX) + 0;
    m_food->setFoodx(hx);
    m_food->setFoody(hy);
    qDebug() << "generateFood+:"<< hx <<"-y:"<< hy;
}

void MessageMgr::start(int w,int h)
{
    isRunning = true;
    m_areaX = w;
    m_areaY = h;
//    qDebug() << "areax:" << w << "-areay:" << h;

    int hx= rand()%(m_areaX) + 0;
    int hy = rand()%(m_areaY) + 0;
    m_snake->setHeadx(hx);
    m_snake->setHeady(hy);

    varTimer->start(tInt);

}
void MessageMgr::stop(){
    isRunning = false;
}
void MessageMgr::runSnakeTimer(){

    if(isRunning){
        move();
        if(collide()){
            emit foodEat();
            generateFood();
            m_punkte++;
            emit punkteChanged();
            emit foodChanged(m_food);
        }
    }
}
Snake* MessageMgr::snake() const{
    return m_snake;
}
void MessageMgr::setSnake(Snake* snake){
    if(m_snake!=snake){
        m_snake = snake;
        emit snakeChanged(snake);
    }
}

void MessageMgr::turn(int direction){
    m_snake->setMoveDirection(direction);
}
void MessageMgr::move(){
    if(m_snake)
        switch(m_snake->moveDirection())
        {
        case 0:         /*left */
            m_snake->setHeadx(m_snake->headx()- 10);
            break;
        case 1:         /*right*/
            m_snake->setHeadx(m_snake->headx()+10);
            break;
        case 2:         /*up*/
            m_snake->setHeady(m_snake->heady()-10);
            break;
        case 3:         /*down*/
            m_snake->setHeady(m_snake->heady()+10);
            break;
        case 4:         /*death*/
            m_snake->setHeadx(0);
            m_snake->setHeady(0);
            break;
        default:        /*death*/
            m_snake->setHeadx(0);
            m_snake->setHeady(0);
            break;
        }
    checkOut();

}

bool MessageMgr::checkOut(){

//    qDebug() << "areax:" << m_areaX << "-areay:" << m_areaY;
//    qDebug() << "hx:" << m_snake->headx() << "-hy:" << m_snake->heady();
//    qDebug() << "sw:" << m_snake->snakeWidth() << "-sh:" << m_snake->snakeHeight();

    if(m_snake->headx() < 0 || m_snake->heady() < 0 || (m_snake->headx()+m_snake->snakeWidth() ) >  m_areaX
            || (m_snake->heady()+ m_snake->snakeHeight()) > m_areaY ) {
        stop();
        return true;
    } else {
        return false;
    }
}

bool MessageMgr::collide(){
    int fx = m_food->foodx();
    int fy = m_food->foody();
    int fxx = fx + m_food->foodWidth();
    int fyy = fy + m_food->foodHeight();

    int sx = m_snake->headx();
    int sy = m_snake->heady();
    int sxx = sx + m_snake->snakeWidth();
    int syy = sy + m_snake->snakeHeight();

    if(fx <= sxx && fxx >= sx && fy <= syy && fyy > sy){
        return true;
    }

//   if(((fx >= sx && fx <= sxx) && (fy >= sy && fy <= syy)) ||
//      ((fx >= sx && fx <= sxx) && (fyy >= sy && fyy <= syy)) ||
//      ((fxx >= sx && fxx <= sxx) && (fy >= sy && fy <= syy)) ||
//      ((fxx >= sx && fxx <= sxx) && (fyy >= sy && fyy <= syy))
//      )
//    {
//        return true;
//    }
    return false;
}

//bool MessageMgr::collide(){
//    if( ((m_snake->heady()+m_snake->snakeHeight()) >= m_food->foody())
//            && (m_snake->heady() <=(  m_food->foody() + m_food->foodHeight())) ) {
//        if( ((m_snake->headx()+m_snake->snakeWidth()) >= m_food->foodx())
//                && (m_snake->headx() <=( m_food->foodx()+m_food->foodWidth())) ) {
//            return true;
//        }
//        return false;
//    }
//    return false;
//}
Food* MessageMgr::food() const{
    return m_food;
}
void MessageMgr::setFood(Food* food){
    if(m_food!=food){
        m_food = food;

        qDebug() << "x:" << food->foodPostion()->xKoordinate() << "y:" << food->foodPostion()->yKoordinate() ;
        emit foodChanged(food);
    }
}

int MessageMgr::punkte() const{
    return m_punkte;
}
void MessageMgr::setPunkte(int x){
    if(m_punkte!=x){
        m_punkte = x;
        emit punkteChanged();
    }
}
