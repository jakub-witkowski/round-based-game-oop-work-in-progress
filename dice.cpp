#include <random>

int dice()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,100);
    auto random_int = std::bind(distribution, generator);

    return random_int();
}