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

class Game
{
public:
    Game();
    QGraphicsView * view;
    QGraphicsScene * scene;
    Player * player;
    Level * level;

    void loadLevels();
};

#endif // GAME_H
