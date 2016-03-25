#include "lives.h"
#include <QFont>
Lives::Lives():value(3)
{
    setPlainText(QString("Lives: ") + QString::number(value));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",18));
}

void Lives::updateText()
{
     setPlainText(QString("Lives: ") + QString::number(value));
}

