#ifndef COORDINATE_H
#define COORDINATE_H

#include <QObject>
class Coordinate : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int xKoordinate READ xKoordinate WRITE setXKoordinate NOTIFY xKoordinateChanged)
    Q_PROPERTY(int yKoordinate READ yKoordinate WRITE setYKoordinate NOTIFY yKoordinateChanged)

public:
    explicit Coordinate(QObject *parent = nullptr);
    ~Coordinate() override;

    int xKoordinate() const;
    void setXKoordinate(int isCapturing);

    int yKoordinate() const;
    void setYKoordinate(int isCapturing);

signals:
    void xKoordinateChanged(int x);
    void yKoordinateChanged(int x);

public slots:

private:
    int m_xKoordinate;
    int m_yKoordinate;
};

#endif // COORDINATE_H
