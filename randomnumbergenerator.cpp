#include "randomnumbergenerator.h"

RandomNumberGenerator::RandomNumberGenerator():gen(std::random_device()())
{

}

int RandomNumberGenerator::getRandomInt(int a, int b)
{
    std::uniform_int_distribution<int> dis(a, b);
    int random = dis(gen);
    return random;
}
