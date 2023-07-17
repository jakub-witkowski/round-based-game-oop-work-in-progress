#include <iostream>
#include "unit.h"
#include "map_size.h"

class Base // : public Unit
{
    public:
    char type;
    char affiliation;
    int id;
    int x_coord;
    int y_coord;
    int current_stamina;
    bool is_base_busy;

    Base(char aff, int* u)
    {
        type = 'B';
        affiliation = aff;

        if (affiliation == 'P')
        {
            id = 0;
            (*u)++;
        }
        else
        {
            id = 1;
            (*u)++;
        }

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

        current_stamina = 200;
        is_base_busy = false;

        std::cout
        << "\nBase: " << std::endl
        << "affiliation: " << affiliation << std::endl
        << "unit id: " << id <<std::endl
        << "x coord: " << x_coord << std::endl
        << "y coord: " << y_coord << std::endl
        << "stamina: " << current_stamina << std::endl
        << "is base busy?: " << is_base_busy << std::endl
        << "number of units on the map: " << *u << std::endl;
    }

    void train()
    {

    }
};