#include "game.h"
#include <QDebug>
#include <QFont>
#include <QFontDatabase>

Game::Game()
{
    view = new QGraphicsView;
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(Settings::WindowWidth,Settings::WindowHeight);
    view->setSceneRect(0,0,Settings::WindowWidth,Settings::WindowHeight);
    view->show();

    loadMainMenu();

}

void Game::setupPlayer()
{
    player = new Player;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    auto offset = 50;
    player->setPos(view->width()/2 - player->boundingRect().width()/2,Settings::WindowHeight - offset);

    view->scene()->addItem(player);

    QTimer * timer = new QTimer;
    connect(timer,QTimer::timeout,player,&Player::move);
    timer->start(20);

    auto margin = 20;
    player->getLives()->setPos(margin,margin);
    player->getScore()->setPos(Settings::WindowWidth - player->getScore()->boundingRect().width(),margin);

    view->scene()->addItem(player->getLives());
    view->scene()->addItem(player->getScore());

}

void Game::setupBall()
{
    ball = new Ball;

    auto offset = 55;
    ball->setPos(view->width()/2 - ball->ballSize/2,Settings::WindowHeight - ball->ballSize - offset);
    view->scene()->addItem(ball);

    connect(ball,&Ball::ballDestroyed,this,&Game::onBallDestroyed);
    connect(player,&Player::startBallMovement,ball,&Ball::changeMoving);

    QTimer * timer = new QTimer;
    connect(timer,QTimer::timeout,ball,&Ball::move);
    timer->start(20);
}

void Game::loadLevels()
{
    level = new Level(2);

    for(auto block: level->blocks)
    {
        view->scene()->addItem(block);
        block->setPos(block->point);
        connect(block,&Block::blockDamaged,player,&Player::onBlockDamaged);
    }

    QPixmap levelBackground(":/res/backgrounforgame.png");
    view->scene()->setBackgroundBrush(levelBackground);
}

void Game::loadMainMenu()
{
    scene = new QGraphicsScene;scene = new QGraphicsScene;
    view->setScene(scene);

    QPixmap menuBackground(":/res/backgrounforgame.png");
    view->scene()->setBackgroundBrush(menuBackground);

    QGraphicsTextItem *title = new QGraphicsTextItem;

    title->setPlainText(QString("QTARKANOID"));
    title->setFont(Utils::getCommonFont(32));
    scene->addItem(title);
    title->setPos(Settings::WindowWidth/2 - title->boundingRect().width()/2,Settings::WindowHeight/3);

    MenuButton * playButton = new MenuButton(QString("PLAY"));
    scene->addItem(playButton);
    playButton->setPos(Settings::WindowWidth/2 - playButton->boundingRect().width()/2,Settings::WindowHeight/2);
    connect(playButton,&MenuButton::menuButtonPressed,this,&Game::onPlayButtonPressed);
}

void Game::gameOver()
{
    scene = new QGraphicsScene;
    view->setScene(scene);

    QPixmap menuBackground(":/res/backgrounforgame.png");
    view->scene()->setBackgroundBrush(menuBackground);

    QGraphicsTextItem *message = new QGraphicsTextItem;

    message->setPlainText(QString("YOU LOSE, FELLA.\n\nYOUR SCORE: %1").arg(QString::fromStdString(player->getScore()->getScore())));
    message->setFont(Utils::getCommonFont(26));
    scene->addItem(message);
    message->setPos(Settings::WindowWidth/2 - message->boundingRect().width()/2,Settings::WindowHeight/3);

    MenuButton * playButton = new MenuButton(QString("PLAY AGAIN"));
    scene->addItem(playButton);
    playButton->setPos(Settings::WindowWidth/2 - playButton->boundingRect().width()/2,Settings::WindowHeight-playButton->boundingRect().height());
    connect(playButton,&MenuButton::menuButtonPressed,this,&Game::onPlayButtonPressed);

}



void Game::onBallDestroyed()
{
    disconnect(player,&Player::startBallMovement,ball,&Ball::changeMoving);
    delete ball;

    player->getLives()->decreaseLives();

    if(player->getLives()->getValue())
        setupBall();
    else gameOver();
}

void Game::onPlayButtonPressed()
{
    scene = new QGraphicsScene;
    view->setScene(scene);

    setupPlayer();
    setupBall();
    loadLevels();
}


