#ifndef MAINMENU_H
#define MAINMENU_H
#include "settings.h"
#include "menubutton.h"
#include "utils.h"
#include "game.h"

class Game;
class MainMenu:public QGraphicsScene
{
    Q_OBJECT
public:
    MainMenu();
    ~MainMenu();
    void connectMenuControls(Game * game);
    void getNextMenuItem();
private:
    QPointer<QGraphicsTextItem> title;
    QPointer<MenuButton> playButton;
    QPointer<MenuButton> leftNavigationButton;
    QPointer<MenuButton> rightNavigationButton;
    QPointer<MenuButton> quitButton;

};

#endif // MAINMENU_H
