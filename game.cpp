#include "game.h"
#include <QDebug>
#include <QFont>
#include <QFontDatabase>

Game::Game():QGraphicsView()
{

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(Settings::WindowWidth,Settings::WindowHeight);
    setSceneRect(0,0,Settings::WindowWidth,Settings::WindowHeight);
    show();
    loadMainMenu();
}

void Game::setupPlayer()
{
    player = new Player;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    auto offset = 50;
    player->setPos(width()/2 - player->boundingRect().width()/2,Settings::WindowHeight - offset);
    scene()->addItem(player);

    QTimer * timer = new QTimer(player);
    connect(timer,QTimer::timeout,player,&Player::move);
    timer->start(20);

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

    QTimer * timer = new QTimer(ball);
    connect(timer,QTimer::timeout,ball,&Ball::move);
    timer->start(20);
}

void Game::loadLevels()
{   
    level = new Level(3);

    for(auto block: level->blocks)
    {
        scene()->addItem(block);
        block->setPos(block->point);
        connect(block,&Block::blockDamaged,this,&Game::onBlockDamaged);
    }
    QPixmap menuBackground(":/res/backgrounforgame.png");
    setBackgroundBrush(menuBackground);
}

void Game::loadMainMenu()
{
    if(mainMenu.isNull())
       mainMenu = new MainMenu;
    setScene(mainMenu);

    connect(mainMenu->playButton,&MenuButton::menuButtonPressed,this,&Game::onPlayButtonPressed);
    connect(mainMenu->quitButton,&MenuButton::menuButtonPressed,this,&Game::onQuitButtonPressed);
    connect(mainMenu->rightNavigationButton,&MenuButton::menuButtonPressed,this,&Game::onNavigationButtonPressed);
    connect(mainMenu->leftNavigationButton,&MenuButton::menuButtonPressed,this,&Game::onNavigationButtonPressed);
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
    if(mainMenu->playButton->isVisible())
    {
        mainMenu->playButton->setVisible(false);
        mainMenu->quitButton->setVisible(true);
    }
    else if (mainMenu->quitButton->isVisible())
    {
        mainMenu->playButton->setVisible(true);
        mainMenu->quitButton->setVisible(false);
    }
}

void Game::mouseDoubleClickEvent(QMouseEvent *event)
{
    player->setFocus();
}

void Game::onBlockDamaged()
{
    player->getScore()->increaseScore();
}
