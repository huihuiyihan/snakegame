#include "Coordinate.h"

Coordinate::Coordinate(QObject* parent) : QObject(parent)
{

}
Coordinate::~Coordinate(){

}
int Coordinate::xKoordinate() const{
    return m_xKoordinate;
}
void Coordinate::setXKoordinate(int x){
    if(m_xKoordinate!=x){
        m_xKoordinate = x;
        emit xKoordinateChanged(x);
    }
}
int Coordinate::yKoordinate() const{
    return m_yKoordinate;
}
void Coordinate::setYKoordinate(int y){
    if(m_yKoordinate!=y){
        m_yKoordinate = y;
        emit yKoordinateChanged(y);
    }
}
