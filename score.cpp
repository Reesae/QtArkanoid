#include "score.h"
#include "utils.h"
#include "settings.h"

Score::Score(QString value):value(value)
{
    setPlainText(QString("Score:") + value);
    setDefaultTextColor(Qt::black);
    setFont(Utils::getCommonFont());
}

void Score::increaseScore(int points)
{
    addIntToScore(points);
    while(value.size() < 5)
        value = "0" + value;

    setPlainText(QString("Score:") + value);
}

void Score::addIntToScore(int a)
{
    int temp = value.toInt();
    temp += a;
    value = QString::number(temp);
}

