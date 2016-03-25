#include "lives.h"
#include <QFont>
#include <QFontDatabase>

Lives::Lives():value(3)
{
    int id = QFontDatabase::addApplicationFont(":/res/block.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont blockFont(family);

    setPlainText(QString("Lives: ") + QString::number(value));
    setDefaultTextColor(Qt::red);
    setFont(blockFont);
}

void Lives::updateText()
{
     setPlainText(QString("Lives: ") + QString::number(value));
}

