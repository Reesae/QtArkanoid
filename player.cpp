#include "player.h"
#include <QDebug>
Player::Player()
{
    setRect(0,0,64,16);

    QBrush *brush = new QBrush();
    brush->setStyle(Qt::SolidPattern);
    brush->setColor(QColor(20,20,20));
    setBrush(*brush);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
    {
         if(pos().x()>0)
            setPos(x()-10,y());
    }
    else if(event->key()== Qt::Key_Right)
    {
         if(pos().x() < 800 - boundingRect().width())
             setPos(x()+10,y());
         qDebug()<<pos().x();
    }
    else if(event->key()== Qt::Key_Space)
    {

    }

}

