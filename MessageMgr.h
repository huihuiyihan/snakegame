#ifndef MESSAGEMGR_H
#define MESSAGEMGR_H

#include <QObject>
#include <QTimer>
#include <Snake.h>
#include "Coordinate.h"
#include "Food.h"

class MessageMgr : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Snake* snake READ snake WRITE setSnake NOTIFY snakeChanged)
    Q_PROPERTY(Food* food READ food WRITE setFood NOTIFY foodChanged)
    Q_PROPERTY(int punkte READ punkte WRITE setPunkte NOTIFY punkteChanged)
public:
    explicit MessageMgr(QObject *parent = nullptr);
    virtual ~MessageMgr() override;

    Snake* snake() const;
    void setSnake(Snake* snake);

    void move();
    bool checkOut();

    Food* food() const;
    void setFood(Food* food);

    int punkte() const;
    void setPunkte(int food);

    Q_INVOKABLE void turn(int direction);
signals:
    void snakeChanged(Snake* snake);
    void foodChanged(Food* food);
    void foodEat();
    void punkteChanged();

public slots:
    void start(int w, int h);
    void stop();
    void runSnakeTimer();

private:
    void generateFood();
    bool collide();
    bool started=false;
    bool isRunning = false;
    Snake * m_snake = nullptr;
    Food * m_food = nullptr;

    int m_areaX  = 500;
    int m_areaY  = 500;

    int tInt = 20;
    QTimer *varTimer = nullptr;

    int m_punkte = 0;
};

#endif // MESSAGEMGR_H
