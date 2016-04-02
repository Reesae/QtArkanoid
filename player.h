#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsPixMapItem>
#include <QPoint>
#include <QBrush>
#include <QKeyEvent>
#include <QPointer>
#include "score.h"
#include "lives.h"
#include "settings.h"

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Player();
    ~Player();
    Lives* getLives(){return lives;}
    Score* getScore(){return score;}
private:
    bool isMovingRight;
    bool isMovingLeft;

    int playerSpeedModifier;
    QPointer<Lives> lives;
    QPointer<Score> score;
public slots:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void move();
signals:
    void startBallMovement();
};

#endif // PLAYER_H
