#include "score.h"
#include "utils.h"
#include <QFont>
#include <QFontDatabase>

Score::Score(std::string value):score(value)
{
    setPlainText(QString("Score:") + QString::fromStdString(score));
    setDefaultTextColor(Qt::black);
    setFont(Utils::getCommonFont());
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

