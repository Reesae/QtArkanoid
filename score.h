#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>


class Score:public QGraphicsTextItem
{
public:
    Score();
    void increaseScore();
    inline std::string getScore(){return score;}
private:
    std::string score;
};

#endif // SCORE_H
