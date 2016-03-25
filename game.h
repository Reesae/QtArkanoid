#ifndef GAME_H
#define GAME_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "player.h"
#include "block.h"
#include "ball.h"
#include "level.h"
#include "settings.h"

class Game: public QObject
{
    Q_OBJECT
public:
    Game();
    QGraphicsView * view;
    QGraphicsScene * scene;
    Player * player;
    Level * level;
    Ball * ball;
    void setupPlayer();
    void setupBall();
    void loadLevels();


public slots:
    void onBallDestroyed();
};

#endif // GAME_H
