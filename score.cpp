#include "score.h"
#include "utils.h"
#include <QFont>
#include <QFontDatabase>

Score::Score(QString value):value(value)
{
    setPlainText(QString("Score:") + value);
    setDefaultTextColor(Qt::black);
    setFont(Utils::getCommonFont());
}

void Score::increaseScore()
{
    int temp = value.toInt();
    temp += 10;
    value = QString::number(temp);

    while(value.size() < 5)
        value = "0" + value;

    setPlainText(QString("Score:") + value);
}

