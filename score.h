#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include "utils.h"

class Score:public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score(QString value = QString("00000"));
    void increaseScore(int points);
    inline QString getValue(){return value;}
private:
    QString value;
    void addIntToScore(int a);
};

#endif // SCORE_H
