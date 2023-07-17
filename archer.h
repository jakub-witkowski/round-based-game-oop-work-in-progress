#include <iostream>
#include "unit.h"
#include "map_size.h"

class Archer : public Unit
{
    public:
    int movement_points_left; 
    bool attack_possible;
    int training_time;
    int cost;

    Archer(char aff, int* u)
    {
        type = 'A';
        affiliation = aff;
        id = *u;
        (*u)++;

        if (affiliation == 'P')
        {
            x_coord = 0;
            y_coord = 0;
        } 
        else
        {
            x_coord = map_size_x - 1;
            y_coord = map_size_y - 1;
        }

        stamina = 70;
        movement_points_left = 5;
        attack_possible = true;
        cost = 450;
        training_time = 4;

        std::cout
        << "\nArcher: " << std::endl
        << "affiliation: " << affiliation << std::endl
        << "x coord: " << x_coord << std::endl
        << "y coord: " << y_coord << std::endl
        << "stamina: " << stamina << std::endl
        << "movement points left: " << movement_points_left << std::endl
        << "attack possible?: " << attack_possible << std::endl
        << "number of units on the map: " << *u << std::endl;
    }
};