#include <QApplication>
#include "game.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game * game = new Game;
    a.connect(game,&Game::closeApplication,&a,QApplication::quit);
    return a.exec();
}
