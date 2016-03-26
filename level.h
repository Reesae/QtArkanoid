#ifndef LEVEL_H
#define LEVEL_H
#include "block.h"
#include <vector>
#include <memory>

class Level: public QObject
{
    Q_OBJECT
public:
    Level(int i = 1);
    std::vector<Block*> blocks;
private:
    void loadLevel(const std::vector<Block::BlockColor> & vec);

    using Color = Block::BlockColor;
    const std::vector<Block::BlockColor> BlockColorListLevel1{
        Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,
        Color::RED,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,
        Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::RED,
        Color::BLUE,Color::BLUE,Color::RED, Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE};

    const std::vector<Block::BlockColor> BlockColorListLevel2{
        Color::NONE,Color::NONE,Color::YELLOW,Color::NONE,Color::NONE,Color::NONE,Color::NONE,Color::NONE,Color::YELLOW,Color::NONE,Color::NONE,
        Color::NONE,Color::NONE,Color::YELLOW,Color::NONE,Color::NONE,Color::NONE,Color::NONE,Color::NONE,Color::YELLOW,Color::NONE,Color::NONE,
        Color::NONE,Color::NONE,Color::NONE,Color::YELLOW,Color::NONE,Color::NONE,Color::NONE,Color::YELLOW,Color::NONE,Color::NONE,Color::NONE,
        Color::NONE,Color::NONE,Color::NONE,Color::YELLOW,Color::NONE,Color::NONE,Color::NONE,Color::YELLOW,Color::NONE,Color::NONE,Color::NONE,
        Color::NONE,Color::NONE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::NONE,Color::NONE,
        Color::NONE,Color::NONE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::NONE,Color::NONE,
        Color::NONE,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::NONE,
        Color::NONE,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::BLUE,Color::RED,Color::BLUE,Color::BLUE,Color::NONE,
        Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,
        Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,
        Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,
        Color::BLUE,Color::NONE,Color::BLUE,Color::NONE,Color::NONE,Color::NONE,Color::NONE,Color::NONE,Color::BLUE,Color::NONE,Color::BLUE,
        Color::BLUE,Color::NONE,Color::BLUE,Color::NONE,Color::NONE,Color::NONE,Color::NONE,Color::NONE,Color::BLUE,Color::NONE,Color::BLUE,
        Color::NONE,Color::NONE,Color::NONE,Color::BLUE,Color::BLUE,Color::NONE,Color::BLUE,Color::BLUE,Color::NONE,Color::NONE,Color::NONE,
        Color::NONE,Color::NONE,Color::NONE,Color::BLUE,Color::BLUE,Color::NONE,Color::BLUE,Color::BLUE,Color::NONE,Color::NONE,Color::NONE};


};





#endif // LEVEL_H
