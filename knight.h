#include <iostream>
#include "unit.h"
#include "map_size.h"

class Knight : public Unit
{
    public:
    /*int movement_points_left; 
    bool attack_possible;
    int training_time;
    int cost;*/

    Knight(char aff, int* u)
    {
        type = 'K';
        //affiliation = aff;
        id = *u;
        (*u)++;

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

        current_stamina = 70;
        movement_points_left = 5;
        can_attack_enemy_units = true;
        cost = 450;
        training_time_left = 4;

        std::cout
        << "\nKnight: " << std::endl
        << "affiliation: " << affiliation << std::endl
        << "unit id: " << id <<std::endl
        << "x coord: " << x_coord << std::endl
        << "y coord: " << y_coord << std::endl
        << "stamina: " << current_stamina << std::endl
        << "movement points left: " << movement_points_left << std::endl
        << "attack possible?: " << can_attack_enemy_units << std::endl
        << "number of units on the map: " << *u << std::endl;
    }
};