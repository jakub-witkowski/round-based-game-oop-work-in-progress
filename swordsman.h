#include <iostream>
#include "unit.h"
#include "map_size.h"

class Swordsman : public Unit
{
    public:
    int movement_points_left; 
    bool attack_possible;
    int training_time;
    int cost;

    Swordsman(char aff, int* u)
    {
        type = 'S';
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

        stamina = 50;
        movement_points_left = 2;
        attack_possible = true;
        cost = 200;
        training_time = 3;

        std::cout
        << "\nSwordsman: " << std::endl
        << "affiliation: " << affiliation << std::endl
        << "x coord: " << x_coord << std::endl
        << "y coord: " << y_coord << std::endl
        << "stamina: " << stamina << std::endl
        << "movement points left: " << movement_points_left << std::endl
        << "attack possible?: " << attack_possible << std::endl
        << "number of units on the map: " << *u << std::endl;
    }
};