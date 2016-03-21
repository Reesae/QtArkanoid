#include "block.h"


Block::Block(QPoint point,BlockState lives,unsigned int width, unsigned int height):
    point(point),lives(lives),blockWidth(width),blockHeight(height)
{
    setPixmap(QPixmap(":/res/res/bluebrick.png"));
}

Block::Block()
{
    setPixmap(QPixmap(":/res/res/bluebrick.png"));
}

