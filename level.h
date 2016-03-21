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
    void loadLevel(const std::vector<Block::BlockState> & vec);

    using State = Block::BlockState;
    const std::vector<Block::BlockState> blockStateListLevel1{
        State::BLUE,State::BLUE,State::RED,State::BLUE,State::BLUE,State::RED,State::BLUE,State::BLUE,State::RED,
        State::BLUE,State::BLUE,State::RED,State::BLUE,State::BLUE,State::RED,State::BLUE,State::BLUE,State::RED,
        State::BLUE,State::BLUE,State::RED,State::BLUE,State::BLUE,State::RED,State::BLUE,State::BLUE,State::RED,
        State::BLUE,State::BLUE,State::RED,State::BLUE,State::BLUE,State::RED,State::BLUE,State::BLUE,State::RED,
        State::BLUE,State::BLUE,State::RED,State::BLUE,State::BLUE,State::RED,State::BLUE,State::BLUE};
};



#endif // LEVEL_H
