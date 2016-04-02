#include "block.h"


Block::Block(QPoint point,BlockColor lives,unsigned int width, unsigned int height):
    point(point),lives(lives),blockWidth(width),blockHeight(height)
{
   updateColor();
}

void Block::takeDamage()
{
    if(lives != BlockColor::BLACK)
    {
        lives = static_cast<BlockColor>(static_cast<unsigned int>(lives) - 1);
        emit blockDamaged();
    }
    if(lives == BlockColor::NONE)
        delete this;
    else updateColor();
}

void Block::updateColor()
{

    switch(lives){
    case BlockColor::BLUE:
        setPixmap(QPixmap(":/res/bluebrick.png"));
        break;
    case BlockColor::GREEN:
        setPixmap(QPixmap(":/res/greenbrick.png"));
        break;
    case BlockColor::YELLOW:
        setPixmap(QPixmap(":/res/yellowbrick.png"));
        break;
    case BlockColor::ORANGE:
        setPixmap(QPixmap(":/res/orangebrick.png"));
        break;
    case BlockColor::RED:
        setPixmap(QPixmap(":/res/redbrick.png"));
        break;
    case BlockColor::BLACK:
        setPixmap(QPixmap(":/res/blackbrick.png"));
        break;
    case BlockColor::NONE:
        break;
    }

}

