#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QPoint>
#include <QBrush>
#include <QKeyEvent>
#include "score.h"
#include "lives.h"
#include "settings.h"

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Player();

    Lives* getLives(){return lives;}
    Score* getScore(){return score;}
private:
    bool isMovingRight;
    bool isMovingLeft;

    int playerSpeedModifier;
    Lives* lives;
    Score* score;
public slots:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void move();
    void onBlockDamaged();
signals:
    void startBallMovement();
};

#endif // PLAYER_H
