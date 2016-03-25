#include "score.h"
#include <QFont>

Score::Score():score("00000")
{
    setPlainText(QString("Score:") + QString::fromStdString(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",18));
}

void Score::increaseScore()
{
    int temp = std::stoi(score);
    temp+=10;
    score = std::to_string(temp);

    while(score.size() < 5)
        score = "0" + score;

    setPlainText(QString("Score:") + QString::fromStdString(score));
}

