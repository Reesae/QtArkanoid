#include "score.h"
#include <QFont>
#include <QFontDatabase>
Score::Score():score("00000")
{
    int id = QFontDatabase::addApplicationFont(":/res/block.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont blockFont(family);

    setPlainText(QString("Score:") + QString::fromStdString(score));
    setDefaultTextColor(Qt::black);
    setFont(blockFont);
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

