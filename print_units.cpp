#include <iostream>
#include <iomanip>
#include <vector>
#include "unit.h"

void print_units(std::vector<Unit*> u)
{
    /* print units */
            std::cout
            << std::endl
            << " Id:"
            << std::setw(9) << "Aff"
            << std::setw(9) << "Type"
            << std::setw(9) << "X, Y"
            << std::setw(9) << "St"
            << std::setw(9) << "Time"
            << std::setw(9) << "Busy"
            << std::endl;

        for (int i = 0; i < u.size(); i++)
        {
            std::cout
            << " " << u[i]->get_id()
            << std::setw(9) << u[i]->get_affiliation()
            << std::setw(9) << u[i]->get_type()
            << std::setw(9) << u[i]->get_coordinates().first << ", " 
            << std::setw(3) << u[i]->get_coordinates().second << ""
            << std::setw(9) << u[i]->get_current_stamina()
            << std::setw(9) << u[i]->get_training_time_left();

            if (i == 0 || i == 1)
            {
                std::cout
                << std::setw(9) << u[i]->get_is_base_busy();
            }
            
            std::cout
            << std::endl; 
        }
}