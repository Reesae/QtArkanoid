#include "level.h"
#include <QDebug>
Level::Level(int i)
{
    if(i == 1)
        loadLevel(BlockColorListLevel1);
    else if (i == 2)
        loadLevel(BlockColorListLevel2);
}

void Level::loadLevel(const std::vector<Block::BlockColor> &vec)
{
    QPoint start(Settings::HorizontalMargin,Settings::VerticalMargin);
    const unsigned int offset = 2;

    for(auto color : vec)
    {
        if(color != Block::BlockColor::NONE)
        {
            auto b = new Block(start,color,Settings::BlockWidth,Settings::BlockHeight);
            blocks.push_back(b);
        }

        start.setX(start.x() + Settings::BlockWidth + offset);
        if(start.x() > Settings::WindowWidth - Settings::BlockWidth)
        {
            start.setX(Settings::HorizontalMargin);
            start.setY(start.y() + Settings::BlockHeight + offset);
        }
    }
}
