#include "game.h"
#include <QDebug>
#include <QFont>
#include <QFontDatabase>

Game::Game()
{
    scene = new QGraphicsScene;

    QBrush *brush = new QBrush(QColor(230,230,230));
    scene->setBackgroundBrush(*brush);

    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(Settings::WindowWidth,Settings::WindowHeight);
    view->setSceneRect(0,0,Settings::WindowWidth,Settings::WindowHeight);
    loadMainMenu();

}

void Game::setupPlayer()
{
    player = new Player;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    view->scene()->addItem(player);

    auto offset = 50;
    player->setPos(view->width()/2 - player->boundingRect().width()/2,Settings::WindowHeight - offset);

    QTimer * timer = new QTimer();
    connect(timer,QTimer::timeout,player,&Player::move);
    timer->start(20);

    view->scene()->addItem(player->getLives());
    view->scene()->addItem(player->getScore());

    auto margin = 20;
    player->getLives()->setPos(margin,margin);
    player->getScore()->setPos(Settings::WindowWidth - player->getScore()->boundingRect().width() - margin,margin);


}

void Game::setupBall()
{
    ball = new Ball;
    view->scene()->addItem(ball);

    auto offset = 55;
    ball->setPos(view->width()/2 - ball->ballSize/2,Settings::WindowHeight - ball->ballSize - offset);

    connect(ball,&Ball::ballDestroyed,this,&Game::onBallDestroyed);
    connect(player,&Player::startBallMovement,ball,&Ball::changeMoving);

    QTimer * timer = new QTimer();
    connect(timer,QTimer::timeout,ball,&Ball::move);
    timer->start(20);
}

void Game::loadLevels()
{
    level = new Level(2);
    for(auto b: level->blocks)
    {
        view->scene()->addItem(b);
        b->setPos(b->point);
        connect(b,&Block::blockDamaged,player,&Player::onBlockDamaged);
    }
    QPixmap levelBackground(":/res/backgrounforgame.png");
    view->scene()->setBackgroundBrush(levelBackground);
}

void Game::loadMainMenu()
{
    scene = new QGraphicsScene;scene = new QGraphicsScene;
    view->setScene(scene);

    QPixmap menuBackground(":/res/menubackground.png");
    view->scene()->setBackgroundBrush(menuBackground);

    int id = QFontDatabase::addApplicationFont(":/res/block.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont blockFont(family,32);

    QGraphicsTextItem *title = new QGraphicsTextItem;

    title->setPlainText(QString("QTARKANOID"));
    title->setFont(blockFont);
    scene->addItem(title);
    title->setPos(Settings::WindowWidth/2 - title->boundingRect().width()/2,Settings::WindowHeight/3);

    MenuButton * playButton = new MenuButton(QString("PLAY"));
    scene->addItem(playButton);
    playButton->setPos(Settings::WindowWidth/2 - playButton->boundingRect().width()/2,Settings::WindowHeight/2);
    connect(playButton,&MenuButton::menuButtonPressed,this,&Game::onMenuButtonPressed);
}



void Game::onBallDestroyed()
{
    disconnect(player,&Player::startBallMovement,ball,&Ball::changeMoving);
    delete ball;

    player->getLives()->decreaseLives();
    if(player->getLives()->getValue())
        setupBall();
}

void Game::onMenuButtonPressed()
{
    scene = new QGraphicsScene;
    view->setScene(scene);

    setupPlayer();
    setupBall();
    loadLevels();

}


