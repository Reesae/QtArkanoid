#include "menubutton.h"
#include "utils.h"
#include "settings.h"

MenuButton::MenuButton(QString title)
{
    setPlainText(title);
    setFont(Utils::getCommonFont(Settings::MenuButtonFontSize));
}

void MenuButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit menuButtonPressed();
}

