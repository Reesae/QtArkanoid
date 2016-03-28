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
#include "menubutton.h"
#include "utils.h"
#include "mainmenu.h"
#include "summaryscreen.h"
class Game: public QObject
{
    Q_OBJECT
public:
    Game();
private:
    QGraphicsView * view;
    QGraphicsScene * scene;
    Player * player;
    Level * level;
    Ball * ball;
    MainMenu * mainMenu;
    SummaryScreen * summaryScreen;
    void setupPlayer();
    void setupBall();
    void loadLevels();
    void loadMainMenu();
    void gameOver();

public slots:
    void onBallDestroyed();
    void onPlayButtonPressed();
};

#endif // GAME_H
