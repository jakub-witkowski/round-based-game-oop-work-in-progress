#include <iostream>
#include "unit.h"
#include "map_size.h"

class Swordsman : public Unit
{
    public:

    Swordsman(char aff, long* g, int* u)
    {
        type = 'S';        
        current_stamina = 60;
        movement_points_left = 2;
        can_attack_enemy_units = true;
        cost = 250;
        training_time_left = 3;
        attack_range = 1;

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
        << "\nSwordsman: " << std::endl
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