#include <random>

int dice()
{
    /*std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,100);
    auto random_int = std::bind(distribution, generator);*/

    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<> distr(1, 100); // define the range
    int dice_roll = distr(gen);

    return dice_roll;
}