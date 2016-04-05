#include "player.h"
#include "playerpowerup.h"
#include <QDebug>

Player::Player():moveTimer(nullptr),power(PlayerPowerType::NONE),isMovingRight(false),isMovingLeft(false),playerSpeedModifier(10)
{
    setPixmap(QPixmap(":/res/player.png"));

    lives = new Lives();
    score = new Score();

    moveTimer = new QTimer(this);
    connect(moveTimer,QTimer::timeout,this,&Player::move);
    moveTimer->start(20);

}

Player::~Player()
{
    delete score;
    delete lives;
}


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
        isMovingLeft = isOnScreenBounds() ? true : false;

    else if(event->key() == Qt::Key_Right)
        isMovingRight = isOnScreenBounds() ? true : false;

    else if(event->key() == Qt::Key_Space)
        emit startBallMovement();
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
        isMovingLeft = false;
    else if(event->key() == Qt::Key_Right)
        isMovingRight = false;
}

bool Player::isOnScreenBounds()
{
    if(pos().x() > 0 && pos().x() < Settings::WindowWidth - boundingRect().width())
        return true;
    else return false;
}

void Player::checkCollisions()
{
    QList<QGraphicsItem*> collidingObjects = collidingItems();
    for(QGraphicsItem* item : collidingObjects)
    {
        if(typeid(*item)== typeid(PlayerPowerUp))
            static_cast<PlayerPowerUp*>(item)->activate(this);
    }
}

void Player::move()
{
    if(isMovingLeft)
        if(isOnScreenBounds())
           setX(x() - playerSpeedModifier);

    if(isMovingRight)
        if(isOnScreenBounds())
            setX(x() + playerSpeedModifier);

    checkCollisions();

}


