#include "block.h"


Block::Block(QPoint point,BlockState lives,unsigned int width, unsigned int height):
    point(point),lives(lives),blockWidth(width),blockHeight(height)
{
   updateColor();
}

void Block::takeDamage()
{
    if(lives != BlockState::BLACK)
    {
        lives = static_cast<BlockState>(static_cast<unsigned int>(lives) - 1);
        emit blockDamaged();
    }
    if(lives == BlockState::NONE)
        delete this;
    else updateColor();
}

void Block::updateColor()
{
    switch(lives){
    case BlockState::BLUE:
        setPixmap(QPixmap(":/res/bluebrick.png"));
        break;
    case BlockState::GREEN:
        setPixmap(QPixmap(":/res/greenbrick.png"));
        break;
    case BlockState::YELLOW:
        setPixmap(QPixmap(":/res/yellowbrick.png"));
        break;
    case BlockState::ORANGE:
        setPixmap(QPixmap(":/res/orangebrick.png"));
        break;
    case BlockState::RED:
        setPixmap(QPixmap(":/res/redbrick.png"));
        break;
    case BlockState::BLACK:
        setPixmap(QPixmap(":/res/blackbrick.png"));
        break;
    case BlockState::NONE:
        break;
    }

}

