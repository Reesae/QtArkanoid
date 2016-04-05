#ifndef PLAYERPOWERUP_H
#define PLAYERPOWERUP_H
#include "powerup.h"

enum class PlayerPowerType: unsigned int {NONE = 0, LARGE_PAD = 1,SMALL_PAD = 2,SCORE = 3};

class PlayerPowerUp: public PowerUp
{
public:
    PlayerPowerUp(PlayerPowerType powerType);
    virtual void activate(Player * p) override;
    virtual void deactivate() override;
    virtual void move() override;
private:
    PlayerPowerType power;
    QPointer<Player> player;
    void startTimer(int duration);
    const int powerUpDuration = 10000;

};

#endif // PLAYERPOWERUP_H
