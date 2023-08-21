#include <iostream>
#include <vector>
//#include <random>
#include <unistd.h>

/* header files defining classes */
#include "unit.h"
#include "base.h"
#include "knight.h"
#include "swordsman.h"
#include "catapult.h"
#include "archer.h"
#include "pikeman.h"
#include "worker.h"
#include "ram.h"

/* defining map size */
#include "map_size.h"

/* function declarations */
extern int dice(int min, int max);
extern void train(int (*r)(int min, int max), char aff, long* g);

long gold{2000}; // variable holding the current amount of gold

/* round counters */
int player1_round_counter{1};
int player2_round_counter{1};

int main()
{
    /* Declaring the vector to hold unit data */
    std::vector<Unit*> units = {new Base('P'), new Base('E')};

    //units.push_back(new Knight('P', &gold));
    //units.push_back(new Archer('E', &gold));

    while(player1_round_counter + player2_round_counter < 1000)
    {
        std::cout
        << "Player 1, round "
        << player1_round_counter << std::endl;

        /* updating training times */
        for (int i = 0; i< units.size(); i++)
        {
            units[i]->update_training_time(units);
        }

            std::cout
            << std::endl
            << "Id:\t|" << " Aff\t|" << " Type\t|" << " X, Y\t" << " St";

        for (int i = 0; i< units.size(); i++)
        {
            std::cout
            << std::endl
            << units[i]->get_id() << "\t" << units[i]->get_affiliation() << "\t" << units[i]->get_type() << "\t" << units[i]->get_coordinates().first << ", " << units[i]->get_coordinates().second << "\t" << units[i]->get_current_stamina() << std::endl; 
        }

        /* checking conditions for training a new unit; rolling dice if the conditions are satisfied*/ 
        if (units[0]->get_is_base_busy() != 0)
            std::cout << "Training in progress, cannot train new units." << std::endl;
        if (units[0]->get_is_base_busy() == 0 && gold < 100)
            std::cout << "Insufficient gold for training new units." << std::endl;
        if (units[0]->get_is_base_busy() == 0 && gold > 100)
        {
            if (dice(1, 100) > 50)
                train(&dice, units[0]->get_affiliation(), &gold);
            else
                std::cout << "No training ordered." << std::endl;
        }

        /* ordering units to move */
        for (int i = 0; i < units.size(); i++)
            units[i]->move(&dice, units[i]->get_affiliation(), map_size_x, map_size_y);

        player1_round_counter++;
    }

    sleep(2);
    return 0;
}