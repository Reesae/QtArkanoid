#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H
#include <random>

class RandomNumberGenerator
{
public:
    RandomNumberGenerator();
    int getRandomInt(int a,int b);
private:
    std::mt19937 gen;
};

#endif // RANDOMNUMBERGENERATOR_H
