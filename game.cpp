#include "game.h"
#include <QDebug>
#include <QFont>
#include <QFontDatabase>

Game::Game():QGraphicsView(),generator()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(Settings::WindowWidth,Settings::WindowHeight);
    setSceneRect(0,0,Settings::WindowWidth,Settings::WindowHeight);
    loadMainMenu();
    show();
}
void Game::setupPlayer()
{
    player = new Player;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    auto offset = 50;
    player->setPos(width()/2 - player->boundingRect().width()/2,Settings::WindowHeight - offset);
    scene()->addItem(player);

    auto margin = 20;
    player->getLives()->setPos(margin,margin);
    player->getScore()->setPos(Settings::WindowWidth - player->getScore()->boundingRect().width(),margin);

    scene()->addItem(player->getLives());
    scene()->addItem(player->getScore());
}

void Game::setupBall()
{
    ball = new Ball;

    auto offset = 55;
    ball->setPos(width()/2 - ball->ballSize/2,Settings::WindowHeight - ball->ballSize - offset);
    scene()->addItem(ball);

    connect(ball,&Ball::ballDestroyed,this,&Game::onBallDestroyed);
    connect(player,&Player::startBallMovement,ball,&Ball::changeMoving);
}

void Game::loadLevels()
{   
    level = new Level(2);

    for(auto block: level->blocks)
    {
        scene()->addItem(block);
        block->setPos(block->point);
        connect(block,&Block::blockDamaged,this,&Game::onBlockDamaged);
        connect(block,&Block::blockDamaged,this,&Game::spawnPlayerPowerUp);
    }
    QPixmap menuBackground(":/res/backgrounforgame.png");
    setBackgroundBrush(menuBackground);
}

void Game::loadMainMenu()
{
    if(mainMenu.isNull())
       mainMenu = new MainMenu;
    setScene(mainMenu);
    mainMenu->connectMenuControls(this);
}

void Game::gameOver()
{
    if(summaryScreen.isNull())
    {
        summaryScreen = new SummaryScreen(player->getScore()->getValue());
        connect(summaryScreen->playAgainButton,&MenuButton::menuButtonPressed,this,&Game::onPlayButtonPressed);
    }
    else  emit closeApplication();
    summaryScreen->updateScore(player->getScore()->getValue());

    delete level;
    delete player;
    delete scene();

    setScene(summaryScreen);
}

void Game::onBallDestroyed()
{
    scene()->removeItem(ball);
    ball->destroyBall();

    player->getLives()->decreaseLives();
    if(player->getLives()->getValue())
        setupBall();
    else gameOver();
}

void Game::onPlayButtonPressed()
{
    QGraphicsScene* scene = new QGraphicsScene;
    setScene(scene);

    setupPlayer();
    setupBall();
    loadLevels();
}

void Game::onQuitButtonPressed()
{
    emit closeApplication();
}

void Game::onNavigationButtonPressed()
{
    mainMenu->getNextMenuItem();
}

void Game::mouseDoubleClickEvent(QMouseEvent *event)
{
    player->setFocus();
}

void Game::onBlockDamaged()
{
    player->getScore()->increaseScore(Settings::BlockPointsPerDmg);
}

void Game::spawnPlayerPowerUp()
{
    int rand = generator.getRandomInt(1,6);
    if(rand == 1)
    {
        PlayerPowerUp * p = new PlayerPowerUp(PlayerPowerType::LARGE_PAD);
        p->setPos(ball->x(),ball->y()-16);
        scene()->addItem(p);
    }
    else if(rand == 2)
    {
        PlayerPowerUp * p = new PlayerPowerUp(PlayerPowerType::SMALL_PAD);
        p->setPos(ball->x(),ball->y()-16);
        scene()->addItem(p);
    }

}
