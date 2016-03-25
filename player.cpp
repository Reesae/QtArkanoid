#include "player.h"
#include <QDebug>

Player::Player():isMovingRight(false),isMovingLeft()
{
    setRect(0,0,64,16);

    QBrush *brush = new QBrush();
    brush->setStyle(Qt::SolidPattern);
    brush->setColor(QColor(20,20,20));
    setBrush(*brush);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
    {
         if(pos().x()>0)
            isMovingLeft = true;
    }
    else if(event->key()== Qt::Key_Right)
    {
         if(pos().x() < Settings::WindowWidth - boundingRect().width())
            isMovingRight = true;
         else isMovingRight = false;
    }
    else if(event->key()== Qt::Key_Space)
    {
         emit startBallMovement();
    }

}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
         isMovingLeft = false;
    else if(event->key()== Qt::Key_Right)
         isMovingRight = false;

}

void Player::move()
{
    if(isMovingLeft)
       setX(x() - 8);
    else if(isMovingRight)
       setX(x() + 8);

}
