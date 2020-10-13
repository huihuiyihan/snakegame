#ifndef FOOD_H
#define FOOD_H

#include <QObject>
#include "Coordinate.h"
#include <QDebug>

class Food : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int foodWidth READ foodWidth WRITE setFoodWidth NOTIFY foodWidthChanged)
    Q_PROPERTY(int foodHeight READ foodHeight WRITE setFoodHeight NOTIFY foodHeightChanged)

    Q_PROPERTY(int foodx READ foodx WRITE setFoodx NOTIFY foodxChanged)
    Q_PROPERTY(int foody READ foody WRITE setFoody NOTIFY foodxChanged)
    Q_PROPERTY(Coordinate* foodPostion READ foodPostion WRITE setFoodPostion NOTIFY foodPostionChanged)
public:
    explicit Food(QObject *parent = nullptr);

    int foodWidth() const;
    void setFoodWidth(int x);

    int foodHeight() const;
    void setFoodHeight(int x);


    int foodx() const;
    void setFoodx(int x);

    int foody() const;
    void setFoody(int y);


    Coordinate* foodPostion() const;
    void setFoodPostion(Coordinate* food);

    void changePosition(int x, int y);

signals:
    void foodWidthChanged(int x);
    void foodHeightChanged(int x);
    void foodxChanged(int x);
    void foodyChanged(int y);
    void foodPostionChanged();

public slots:

private:
    int m_foodWidth = 0;
    int m_foodHeight = 0;
    int m_foodx = 0;
    int m_foody = 0;
    Coordinate * m_food = nullptr;
};

#endif // FOOD_H
