#ifndef POWERUP_H
#define POWERUP_H
#include "utils.h"
#include "player.h"

class Player;

class PowerUp: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PowerUp();
    virtual void activate(Player * p) = 0;
    virtual void deactivate() = 0;
    virtual void move() = 0;
    QTimer * timer;
};

#endif // POWERUP_H
