#include "lives.h"
#include "utils.h"
#include <QFont>
#include <QFontDatabase>

Lives::Lives(int value):value(value)
{
    setPlainText(QString("Lives: ") + QString::number(value));
    setDefaultTextColor(Qt::red);
    setFont(Utils::getCommonFont());
}

void Lives::updateText()
{
     setPlainText(QString("Lives: ") + QString::number(value));
}

