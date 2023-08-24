#include <iostream>
#include "unit.h"
#include "map_size.h"

#ifndef BASE_H
#define BASE_H

class Base : public Unit
{
    public:

    Base(char aff)
    {
        set_type('B');
        set_affiliation(aff);

        if (get_affiliation() == 'P')
        {
            set_id(0);
            update_unit_counter(1);
        }
        else if (get_affiliation() == 'E')
        {
            set_id(1);
            update_unit_counter(1);
        }

        if (get_affiliation() == 'P')
        {
            set_coordinates(0,0);
        } 
        else
        {
            set_coordinates(map_size_x - 1, map_size_y - 1);
        }

        set_current_stamina(200);
        set_is_base_busy(false);

        /*std::cout
        << "\nBase: " << std::endl
        << "affiliation: " << get_affiliation() << std::endl
        << "unit id: " << get_id() <<std::endl
        << "x coord: " << get_coordinates().first << std::endl
        << "y coord: " << get_coordinates().second << std::endl
        << "stamina: " << get_current_stamina() << std::endl
        << "is base busy?: " << get_is_base_busy() << std::endl
        << "number of units on the map: " << get_number_of_active_units() << std::endl;*/
    }

    ~Base()
    {
        
    }

    void train()
    {

    }
};

#endif