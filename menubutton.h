#ifndef MENUBUTTON_H
#define MENUBUTTON_H
#include <QObject>
#include <QGraphicsTextItem>
#include <QFont>
#include <QFontDatabase>
#include <QGraphicsSceneMouseEvent>

class MenuButton:public QGraphicsTextItem
{
    Q_OBJECT
public:
    MenuButton(QString title);
public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
    void menuButtonPressed();
};

#endif // MENUBUTTON_H
