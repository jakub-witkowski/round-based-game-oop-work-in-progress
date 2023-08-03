#include <iostream>
#include "unit.h"

void Unit::move(int (*r)(int, int), char aff, int* u, const int x, const int y)
{
    if (this->affiliation == aff)
    {
        
    }

    std::cout
    << "Ordering unit "
    << this->id
    << "to move to x: "
    << this->x_coord
    << ", y: "
    << this-> y_coord
    << ". "
    << std::endl;
}