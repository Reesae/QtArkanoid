#ifndef MAINMENU_H
#define MAINMENU_H
#include "settings.h"
#include "menubutton.h"
#include "utils.h"
#include <QGraphicsScene>

class MainMenu:public QGraphicsScene
{
    Q_OBJECT
public:
    MainMenu();
    MenuButton * playButton;
    MenuButton * leftNavigationButton;
    MenuButton * rightNavigationButton;

};

#endif // MAINMENU_H
