#include "ball.h"
#include <QBrush>
#include <QDebug>
#include <typeinfo>
#include <math.h>

Ball::Ball(int size):ballSize(size),moving(false)
{
    moveVector = std::make_pair(0.0,-1.0);
    setRect(0,0,ballSize,ballSize);
    QBrush *brush = new QBrush();
    brush->setStyle(Qt::SolidPattern);
    brush->setColor(QColor(255,20,20));
    setBrush(*brush);

}

void Ball::changeDirection(QGraphicsItem &item)
{
    auto blockPoint = item.pos();
    auto ballPoint = pos() + boundingRect().center();
    auto itemWidth = item.boundingRect().width();
    auto itemHeight = item.boundingRect().height();

    moveVector.first = std::asin(((ballPoint.x()-blockPoint.x())-0.5*itemWidth)/itemWidth);

    if(blockPoint.y() > ballPoint.y())
         moveVector.second = -1.0;
    else if(blockPoint.y() + itemHeight < ballPoint.y())
         moveVector.second = 1.0  ;

}

void Ball::checkCollisions()
{
    QList<QGraphicsItem*> collidingObjects = collidingItems();
    foreach(QGraphicsItem* item,collidingObjects)
    {
        if(typeid(*item)== typeid(Block) || typeid(*item) == typeid(Player))
        {
            changeDirection(*item);
            if(typeid(*item) == typeid(Block))
                static_cast<Block*>(item)->takeDamage();
            return;
        }

    }

}

void Ball::isOnSceneBounds()
{
    if(x() < ballSize)
        moveVector.first *= -1.0;
    else if(x() > Settings::WindowWidth - ballSize)
        moveVector.first *= -1.0;
    else if(y() < ballSize)
        moveVector.second *= -1.0;
    else if(y() > Settings::WindowHeight)
        ballOffScreen();

}

void Ball::ballOffScreen()
{
    emit ballDestroyed();
}

void Ball::changeMoving()
{
    moving = !moving;
}

void Ball::move()
{
    if(moving)
    {
        setX(x() + moveVector.first * 5);
        setY(y() + moveVector.second * 5);
    }

    checkCollisions();
    isOnSceneBounds();
}


