#include "game.h"
#include <QDebug>
Game::Game()
{
    QGraphicsScene *scene = new QGraphicsScene;

    QBrush *brush = new QBrush();
    brush->setStyle(Qt::SolidPattern);
    brush->setColor(QColor(230,230,230));
    scene->setBackgroundBrush(*brush);

    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600);
    view->setSceneRect(0,0,800,600);

    player = new Player;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    player->setPos(view->width()/2,550);
    loadLevels();

    Ball * ball = new Ball;
    view->scene()->addItem(ball);
    ball->setPos(view->width()/2 + player->boundingRect().width()/3,550 - ball->ballSize);


}


void Game::loadLevels()
{
    level = new Level(1);
    for(auto b: level->blocks)
    {
        view->scene()->addItem(b);
        b->setPos(b->getPoint());
    }


}

