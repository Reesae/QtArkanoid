#include "ball.h"
#include <QBrush>
Ball::Ball(int size):ballSize(size),moving(false)
{
    moveVector = std::make_pair(0.0,1.0);
    setRect(0,0,ballSize,ballSize);
    QBrush *brush = new QBrush();
    brush->setStyle(Qt::SolidPattern);
    brush->setColor(QColor(255,20,20));
    setBrush(*brush);

}

void Ball::changeDirection()
{

}

