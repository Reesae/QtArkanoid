#ifndef BALL_H
#define BALL_H
#include <utility>
#include <QObject>
#include <QGraphicsEllipseItem>
#include "block.h"
#include "player.h"
#include "settings.h"

class Ball: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Ball(unsigned int size = Settings::BallSize);
    std::pair<double,double> moveVector;
    void changeDirection(QGraphicsItem & item);
    int ballSize;
private:
    bool moving;
    void checkCollisions();
    void isOnSceneBounds();
    void ballOffScreen();

    int ballSpeedModifier;
public slots:
    void changeMoving();
    void move();
signals:
    void ballDestroyed();
};

#endif // BALL_H
