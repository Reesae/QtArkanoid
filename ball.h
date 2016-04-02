#ifndef BALL_H
#define BALL_H
#include <utility>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "block.h"
#include "player.h"
#include "settings.h"

class Ball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ball(unsigned int size = Settings::BallSize);
    std::pair<double,double> moveVector;
    void changeDirection(QGraphicsItem & item);
    inline void destroyBall(){delete this;}
    int ballSize;
private:
    void checkCollisions();
    void isOnSceneBounds();
    void ballOffScreen();

    bool moving;
    int ballSpeedModifier;
public slots:
    void changeMoving();
    void move();
signals:
    void ballDestroyed();
};

#endif // BALL_H
