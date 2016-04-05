#ifndef BLOCK_H
#define BLOCK_H
#include "utils.h"
#include "settings.h"

class Block: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    enum class BlockColor : unsigned int {NONE = 0,BLUE = 1,GREEN = 2,YELLOW = 3 ,ORANGE = 4,RED = 5,BLACK = 100};

    Block(QPoint point, BlockColor lives = BlockColor::BLUE,
          unsigned int width = Settings::BlockWidth, unsigned int height = Settings::BlockHeight);
    void takeDamage();

    QPoint point;
private:
    void updateColor();

    BlockColor lives;
    unsigned int blockWidth;
    unsigned int blockHeight;
signals:
    void blockDamaged();

};

#endif // BLOCK_H
