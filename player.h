#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsPixMapItem>
#include <QPoint>
#include <QBrush>
#include <QKeyEvent>
#include <QPointer>
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
    inline Lives* getLives(){return lives;}
    inline Score* getScore(){return score;}
    inline int getPower(){return static_cast<int>(power);}
private:
    bool isMovingRight;
    bool isMovingLeft;

    int playerSpeedModifier;
    QPointer<Lives> lives;
    QPointer<Score> score;
    PlayerPowerType power;
    void checkCollisions();
public slots:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void move();
signals:
    void startBallMovement();
};

#endif // PLAYER_H
