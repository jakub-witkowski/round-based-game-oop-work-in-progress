#include <iostream>
#include "unit.h"
#include "map_size.h"

class Knight : public Unit
{
    public:

    Knight(char aff, long* g, int* u)
    {
        type = 'K';
        current_stamina = 70;
        movement_points_left = 5;
        can_attack_enemy_units = true;
        cost = 400;
        training_time_left = 5;
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
        << "\nKnight: " << std::endl
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