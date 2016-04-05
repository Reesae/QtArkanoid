#ifndef GAME_H
#define GAME_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "block.h"
#include "ball.h"
#include "level.h"
#include "settings.h"
#include "menubutton.h"
#include "utils.h"
#include "mainmenu.h"
#include "summaryscreen.h"
#include "playerpowerup.h"
#include "randomnumbergenerator.h"

class MainMenu;
class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game();
private:
    QPointer<Player> player;
    Level * level;
    QPointer<Ball> ball;
    QPointer<MainMenu> mainMenu;
    QPointer<SummaryScreen> summaryScreen;
    RandomNumberGenerator generator;

    void setupPlayer();
    void setupBall();
    void loadLevels();
    void loadMainMenu();
    void gameOver();
public slots:
    void onBallDestroyed();
    void onPlayButtonPressed();
    void onQuitButtonPressed();
    void onNavigationButtonPressed();
    void mouseDoubleClickEvent(QMouseEvent *event);
    void onBlockDamaged();
    void spawnPlayerPowerUp();
signals:
    void closeApplication();
};

#endif // GAME_H
