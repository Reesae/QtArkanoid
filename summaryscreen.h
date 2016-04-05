#ifndef SUMMARYSCREEN_H
#define SUMMARYSCREEN_H
#include "settings.h"
#include "menubutton.h"
#include "utils.h"

class SummaryScreen: public QGraphicsScene
{
public:
    SummaryScreen(QString score);
    ~SummaryScreen();
    QPointer<QGraphicsTextItem> message;
    QPointer<MenuButton> playAgainButton;
    void updateScore(QString score);
};

#endif // SUMMARYSCREEN_H
