#include <iostream>
#include "unit.h"
#include "map_size.h"

class Pikeman : public Unit
{
    public:

    Pikeman(char aff, long* g, int* u)
    {
        type = 'P';
        current_stamina = 50;
        movement_points_left = 2;
        can_attack_enemy_units = true;
        cost = 200;
        training_time_left = 3;
        attack_range = 2;
        
        id = *u;
        (*u)++;
        *g -= cost;

        if ((affiliation = aff) == 'P')
        {
            x_coord = 0;
            y_coord = 0;
        } 
        else
        {
            x_coord = map_size_x - 1;
            y_coord = map_size_y - 1;
        }

        std::cout
        << "\nPikeman: " << std::endl
        << "affiliation: " << affiliation << std::endl
        << "unit id: " << id <<std::endl
        << "x coord: " << x_coord << std::endl
        << "y coord: " << y_coord << std::endl
        << "stamina: " << current_stamina << std::endl
        << "movement points left: " << movement_points_left << std::endl
        << "attack possible?: " << can_attack_enemy_units << std::endl
        << "gold left: " << *g << std::endl
        << "number of units on the map: " << *u << std::endl;
    }
};