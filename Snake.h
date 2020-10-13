#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <Coordinate.h>

class MessageMgr;
class Snake : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int snakeWidth READ snakeWidth WRITE setSnakeWidth NOTIFY snakeWidthChanged)
    Q_PROPERTY(int snakeHeight READ snakeHeight WRITE setSnakeHeight NOTIFY snakeHeightChanged)

    Q_PROPERTY(int moveDirection READ moveDirection WRITE setMoveDirection NOTIFY moveDirectionChanged)
    Q_PROPERTY(int headx READ headx WRITE setHeadx NOTIFY headxChanged)
    Q_PROPERTY(int heady READ heady WRITE setHeady NOTIFY headyChanged)
public:
    Snake(MessageMgr *parent = nullptr);
    ~Snake() override;

    int snakeWidth() const;
    void setSnakeWidth(int d);

    int snakeHeight() const;
    Q_INVOKABLE void setSnakeHeight(int d);

    int moveDirection() const;
    void setMoveDirection(int d);


    int headx() const;
    void setHeadx(int x);


    int heady() const;
    void setHeady(int y);


signals:
    void snakeWidthChanged(int d);
    void snakeHeightChanged(int d);

    void moveDirectionChanged(int d);
    void headxChanged(int x);
    void headyChanged(int y);

public slots:

private:
    int m_snakeWidth = 500;
    int m_snakeHeight = 500;
    int areaX = 500;
    int areaY = 500;
    int m_moveDirection = 0;
    int m_headx = 0.5 * areaX;
    int m_heady = 0.5 * areaX;
    int step = 10;
    int timeStep = 50;
    Coordinate *m_headCoordinate = nullptr;


};

#endif // SNAKE_H
