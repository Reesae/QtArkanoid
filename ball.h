#ifndef BALL_H
#define BALL_H
#include <utility>
#include <QObject>
#include <QGraphicsEllipseItem>
class Ball:public QObject,public QGraphicsEllipseItem
{
public:
    Ball(int size = 16);
    std::pair<double,double> moveVector;
    void changeDirection();
    int ballSize;

private:
    bool moving;

public slots:
    void move();
};

#endif // BALL_H
