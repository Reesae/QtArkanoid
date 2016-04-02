#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>


class Score:public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score(QString value = QString("00000"));
    void increaseScore();
    inline QString getValue(){return value;}
private:
    QString value;
};

#endif // SCORE_H
