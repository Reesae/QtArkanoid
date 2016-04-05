#include "player.h"
#include "playerpowerup.h"


PlayerPowerUp::PlayerPowerUp(PlayerPowerType powerType):PowerUp(),power(powerType),player(nullptr)
{
    setPixmap(QPixmap(":/res/ball.png"));
    QTimer * moveTimer = new QTimer(this);
    connect(moveTimer,QTimer::timeout,this,&PlayerPowerUp::move);
    moveTimer->start(20);
}


void PlayerPowerUp::activate(Player * p)
{
    player = p;

    if(power == PlayerPowerType::LARGE_PAD)
    {
        if(timer)
            delete timer;
        player->setPixmap(QPixmap(":/res/largeplayer.png"));
        startTimer(powerUpDuration);
    }
    else
    {
        if(timer)
            delete timer;
        player->setPixmap(QPixmap(":/res/smallplayer.png"));
        startTimer(powerUpDuration);
    }
}

void PlayerPowerUp::deactivate()
{
    player->setPixmap(QPixmap(":/res/player.png"));
    delete this;
}

void PlayerPowerUp::move()
{
    setPos(x(),y() + 15);
}

void PlayerPowerUp::startTimer(const int duration)
{
    timer = new QTimer;
    connect(timer,QTimer::timeout,this,&PlayerPowerUp::deactivate);
    timer->start(duration);
}
