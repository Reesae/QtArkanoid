#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QPoint>
#include <QBrush>
#include <QKeyEvent>

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    Player();
public slots:
    void keyPressEvent(QKeyEvent* event);
};

#endif // PLAYER_H
