#include <iostream>
#include "unit.h"
#include "map_size.h"

class Worker : public Unit
{
    public:

    Worker(char aff, long* g)
    {
        set_type('W');
        set_affiliation(aff);
        set_current_stamina(20);
        set_movement_points_left(2);
        set_can_attack_enemy_units(true);
        set_cost(100);
        set_training_time_left(2);
        set_attack_range(1);

        set_id(get_number_of_active_units());
        update_unit_counter(1);
        *g -= this->get_cost();

        if (this->get_affiliation() == 'P')
        {
            set_coordinates(0,0);
        } 
        else
        {
            set_coordinates(map_size_x - 1, map_size_y - 1);
        }

        std::cout
        << "\nWorker: " << std::endl
        << "affiliation: " << this->get_affiliation() << std::endl
        << "unit id: " << this->get_id() <<std::endl
        << "x coord: " << this->get_coordinates().first << std::endl
        << "y coord: " << this->get_coordinates().second << std::endl
        << "stamina: " << this->get_current_stamina() << std::endl
        << "movement points left: " << this->get_movement_points_left() << std::endl
        << "attack possible?: " << this->get_can_attack_enemy_units() << std::endl
        << "gold left: " << *g << std::endl
        << "number of units on the map: " << get_number_of_active_units() << std::endl;
    }
};