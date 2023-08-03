#include <random>
#include <iostream>

int dice(int min, int max)
{
    /*std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,100);
    auto random_int = std::bind(distribution, generator);*/

    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<> distr(min, max); // define the range
    int dice_roll = distr(gen);
    std::cout << "Dice: " << dice_roll << std::endl;

    return dice_roll;
}