#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QPoint>
#include <QBrush>
#include <QKeyEvent>
#include "settings.h"

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Player();
private:
    bool isMovingRight;
    bool isMovingLeft;
public slots:
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void move();
signals:
    void startBallMovement();
};

#endif // PLAYER_H
