#include "player.h"
#include "playerpowerup.h"
#include <QDebug>

Player::Player():isMovingRight(false),isMovingLeft(false),playerSpeedModifier(10),power(PlayerPowerType::NONE)
{
    setPixmap(QPixmap(":/res/player.png"));

    lives = new Lives();
    score = new Score();
}

Player::~Player()
{
    delete lives;
    delete score;
}

void Player::checkCollisions()
{
    QList<QGraphicsItem*> collidingObjects = collidingItems();
    foreach(QGraphicsItem* item,collidingObjects)
    {
        if(typeid(*item)== typeid(PlayerPowerUp))
            static_cast<PlayerPowerUp*>(item)->activate(this);
    }
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
    {
         if(pos().x() > 0)
            isMovingLeft = true;
    }
    else if(event->key()== Qt::Key_Right)
    {
         if(pos().x() < Settings::WindowWidth - boundingRect().width())
            isMovingRight = true;
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
    {
        if(x() > 0)
           setX(x() - playerSpeedModifier);
    }
    else if(isMovingRight)
    {
        if(x() < Settings::WindowWidth - boundingRect().width())
            setX(x() + playerSpeedModifier);

    }
    checkCollisions();

}


