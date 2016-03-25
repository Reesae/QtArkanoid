#ifndef BLOCK_H
#define BLOCK_H
#include <QObject>
#include <QGraphicsPixMapItem>
#include <QPoint>
#include <QBrush>

class Block: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    enum class BlockState : unsigned int {NONE = 0,BLUE = 1,GREEN = 2,YELLOW = 3 ,ORANGE = 4,RED = 5,BLACK = 100};

    Block(QPoint point, BlockState lives = BlockState::BLUE, unsigned int width = 64, unsigned int height = 32);
    Block();
    inline QPoint& getPoint(){return point;}
    void takeDamage();
private:
    QPoint point;
    BlockState lives;
    unsigned int blockWidth;
    unsigned int blockHeight;

    void updateColor();


};

#endif // BLOCK_H
