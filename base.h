#include <iostream>
#include "unit.h"
#include "map_size.h"

#ifndef BASE_H
#define BASE_H

class Base : public Unit
{
    public:
    /*char type;
    char affiliation;
    int id;
    int x_coord;
    int y_coord;
    int current_stamina;
    bool is_base_busy;*/

    Base(char aff)
    {
        type = 'B';
        affiliation = aff;

        if (affiliation == 'P')
        {
            id = 0;
            number_of_active_units++;
        }
        else
        {
            id = 1;
            number_of_active_units++;
        }

        if ((affiliation = aff) == 'P')
        {
            coordinates = {0,0};
        } 
        else
        {
            coordinates = {map_size_x - 1, map_size_y - 1};
        }

        current_stamina = 200;
        is_base_busy = false;

        std::cout
        << "\nBase: " << std::endl
        << "affiliation: " << affiliation << std::endl
        << "unit id: " << id <<std::endl
        << "x coord: " << coordinates.first << std::endl
        << "y coord: " << coordinates.second << std::endl
        << "stamina: " << current_stamina << std::endl
        << "is base busy?: " << is_base_busy << std::endl
        << "number of units on the map: " << number_of_active_units << std::endl;
    }

    ~Base()
    {
        
    }

    void train()
    {

    }
};

#endif