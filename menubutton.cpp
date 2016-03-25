#include "menubutton.h"

MenuButton::MenuButton(QString title)
{
    int id = QFontDatabase::addApplicationFont(":/res/block.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont blockFont(family,32);
    setPlainText(title);
    setFont(blockFont);
}

void MenuButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit menuButtonPressed();
}

