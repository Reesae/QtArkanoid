#include "mainmenu.h"

MainMenu::MainMenu()
{
    QPixmap menuBackground(":/res/backgrounforgame.png");
    setBackgroundBrush(menuBackground);

    title = new QGraphicsTextItem;
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

    quitButton = new MenuButton(QString("QUIT"));
    addItem(quitButton);
    quitButton->setPos(Settings::WindowWidth/2 - playButton->boundingRect().width()/2,Settings::WindowHeight/2);
    quitButton->setVisible(false);

}

MainMenu::~MainMenu()
{
    delete quitButton;
    delete leftNavigationButton;
    delete rightNavigationButton;
    delete playButton;
    delete title;
}

void MainMenu::connectMenuControls(Game *game)
{
    connect(playButton,&MenuButton::menuButtonPressed,game,&Game::onPlayButtonPressed);
    connect(quitButton,&MenuButton::menuButtonPressed,game,&Game::onQuitButtonPressed);
    connect(rightNavigationButton,&MenuButton::menuButtonPressed,game,&Game::onNavigationButtonPressed);
    connect(leftNavigationButton,&MenuButton::menuButtonPressed,game,&Game::onNavigationButtonPressed);
}

void MainMenu::getNextMenuItem()
{
    if(playButton->isVisible())
    {
        playButton->setVisible(false);
        quitButton->setVisible(true);
    }
    else if (quitButton->isVisible())
    {
        playButton->setVisible(true);
        quitButton->setVisible(false);
    }
}

