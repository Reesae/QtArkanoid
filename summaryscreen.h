#ifndef SUMMARYSCREEN_H
#define SUMMARYSCREEN_H
#include "settings.h"
#include "menubutton.h"
#include "utils.h"
#include <QGraphicsScene>

class SummaryScreen: public QGraphicsScene
{
public:
    SummaryScreen(QString score);
    QGraphicsTextItem * message;
    MenuButton * playAgainButton;
};

#endif // SUMMARYSCREEN_H
