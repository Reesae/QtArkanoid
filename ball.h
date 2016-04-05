#ifndef BALL_H
#define BALL_H
#include "block.h"
#include "player.h"
#include "settings.h"

class Ball: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ball(unsigned int size = Settings::BallSize);
    void changeDirection(QGraphicsItem & item);
    inline void destroyBall(){delete this;}

    int ballSize;
private:
    void checkCollisions();
    void isOnSceneBounds();
    void ballOffScreen();

    QPointer<QTimer> moveTimer;
    std::pair<double,double> moveVector;
    bool isMoving;
    int ballSpeedModifier;
public slots:
    void changeMoving();
    void move();
signals:
    void ballDestroyed();
};

#endif // BALL_H
