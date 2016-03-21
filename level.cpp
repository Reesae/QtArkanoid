#include "level.h"
#include <QDebug>
Level::Level(int i)
{
    if(i == 1)
        loadLevel(blockStateListLevel1);
}

void Level::loadLevel(const std::vector<Block::BlockState> &vec)
{
    QPoint start(37,100);
    const unsigned int offset = 2;

    for(auto blockstate : vec)
    {
        auto b = new Block(start,blockstate,64,32);
        blocks.push_back(b);

        start.setX(start.x() + 64 + offset);
        if(start.x() > 750)
        {
            start.setX(37);
            start.setY(start.y() + 32 + offset);
        }
    }
}
