#include "mainmenu.h"

MainMenu::MainMenu()
{
    QPixmap menuBackground(":/res/backgrounforgame.png");
    setBackgroundBrush(menuBackground);

    QGraphicsTextItem *title = new QGraphicsTextItem;
    title->setPlainText(QString("QTARKANOID"));
    title->setFont(Utils::getCommonFont(32));
    title->setPos(Settings::WindowWidth/2 - title->boundingRect().width()/2,Settings::WindowHeight/3);
    addItem(title);

    playButton = new MenuButton(QString("PLAY"));
    addItem(playButton);
    playButton->setPos(Settings::WindowWidth/2 - playButton->boundingRect().width()/2,Settings::WindowHeight/2);

    leftNavigationButton = new MenuButton(QString("<"));
    rightNavigationButton = new MenuButton(QString(">"));

    auto offset = 250;
    leftNavigationButton->setPos(Settings::WindowWidth/2 - offset - leftNavigationButton->boundingRect().width(),Settings::WindowHeight/2);
    rightNavigationButton->setPos(Settings::WindowWidth/2 + offset,Settings::WindowHeight/2);
    addItem(leftNavigationButton);
    addItem(rightNavigationButton);
}

