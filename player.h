#ifndef PLAYER_H
#define PLAYER_H
#include <QKeyEvent>
#include <typeinfo>
#include "score.h"
#include "lives.h"
#include "settings.h"

class PlayerPowerUp;
enum class PlayerPowerType:unsigned int;

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player();
    ~Player();
    inline QPointer<Lives> getLives(){return lives;}
    inline QPointer<Score> getScore(){return score;}
    inline PlayerPowerType getPower(){return power;}
private:
    bool isOnScreenBounds();
    void checkCollisions();

    QPointer<Lives> lives;
    QPointer<Score> score;
    QPointer<QTimer> moveTimer;
    PlayerPowerType power;

    bool isMovingRight;
    bool isMovingLeft;
    int playerSpeedModifier;
public slots:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void move();
signals:
    void startBallMovement();
};

#endif // PLAYER_H
