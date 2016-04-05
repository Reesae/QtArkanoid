#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <memory>
#include "utils.h"
#include "block.h"



//TODO: add reading levels from file
class Level
{
public:
    Level(int i = 1);
    std::vector<QPointer<Block>> blocks;
    ~Level();
private:
    void loadLevel(const std::vector<Block::BlockColor> & vec);
    void destroyBlocks();


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
    const std::vector<Block::BlockColor> level3{Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE,Color::BLUE};
    const std::vector<Block::BlockColor> level4{Color::BLUE,Color::NONE,Color::NONE,Color::YELLOW,Color::NONE,Color::NONE,Color::NONE,Color::NONE,Color::NONE,Color::YELLOW,Color::NONE,Color::NONE,
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
                };

};





#endif // LEVEL_H
