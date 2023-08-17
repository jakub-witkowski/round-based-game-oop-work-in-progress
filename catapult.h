#include <iostream>
#include "unit.h"
#include "map_size.h"

class Catapult : public Unit
{
    public:

    Catapult(char aff, long* g, int* u)
    {
        type = 'C';
        current_stamina = 50;
        movement_points_left = 2;
        can_attack_enemy_units = true;
        cost = 800;
        training_time_left = 6;
        attack_range = 7;

        id = *u;
        (*u)++;
        *g -= cost;

        if ((affiliation = aff) == 'P')
        {
            coordinates = {0,0};
        } 
        else
        {
            coordinates = {map_size_x - 1, map_size_y - 1};
        }

        std::cout
        << "\nCatapult: " << std::endl
        << "affiliation: " << affiliation << std::endl
        << "unit id: " << id <<std::endl
        << "x coord: " << coordinates.first << std::endl
        << "y coord: " << coordinates.second << std::endl
        << "stamina: " << current_stamina << std::endl
        << "movement points left: " << movement_points_left << std::endl
        << "attack possible?: " << can_attack_enemy_units << std::endl
        << "gold left: " << *g << std::endl
        << "number of units on the map: " << *u << std::endl;
    }
};