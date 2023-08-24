#include <iostream>
#include <iomanip>
#include <vector>
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
#include "print_units.h"
#include "dice.h"
#include "train.h"

/* variables holding the current amount of gold */
long p1_gold{2000}; 
long p2_gold{2000};

/* round counters */
int player1_round_counter{1};
int player2_round_counter{1};

/* Declaring the vector to hold unit data */
std::vector<Unit*> units = {new Base('P'), new Base('E')};

int main()
{
    while(player1_round_counter + player2_round_counter < 1000)
    {
        
    /* =================================================================Player 1 move=================================================================*/

        std::string bar(100, '-');
        std::cout
        << bar
        << std::endl
        << "Player 1, round "
        << player1_round_counter
        << ", units.size() = "
        << units.size()
        << ", gold: "
        << p1_gold
        << std::endl;

        /* updating training times */
        for (int i = 0; i < units.size(); i++)
        {
            units[i]->update_training_time(units, 'P');
        }

        /* print units */
        print_units(units);

        /* checking conditions for training a new unit; rolling dice if the conditions are satisfied*/ 
        if (units[0]->get_is_base_busy() == true)
            std::cout << "Training in progress, cannot train new units." << std::endl;
        if (units[0]->get_is_base_busy() == false && p1_gold < 100)
            std::cout << "Insufficient gold for training new units." << std::endl;
        if (units[0]->get_is_base_busy() == false && p1_gold > 100)
        {
            if (dice(1, 100) > 50)
                train(&dice, 'P', &p1_gold, units);
            else
                std::cout << "No training ordered." << std::endl;
        }

        /* ordering units to move */
        for (int i = 0; i < units.size(); i++)
            units[i]->move(&dice, 'P', map_size_x, map_size_y);

        player1_round_counter++;
        sleep(2);

         /* =================================================================Player 2 move=================================================================*/

        std::cout
        << bar
        << std::endl
        << "Player 2, round "
        << player2_round_counter
        << ", units.size() = "
        << units.size()
        << ", gold: "
        << p2_gold
        << std::endl;

        /* updating training times */
        for (int i = 0; i < units.size(); i++)
        {
            units[i]->update_training_time(units, 'E');
        }

        /* print units */
        print_units(units);

        /* checking conditions for training a new unit; rolling dice if the conditions are satisfied*/ 
        if (units[1]->get_is_base_busy() == true)
            std::cout << "Training in progress, cannot train new units." << std::endl;
        if (units[1]->get_is_base_busy() == false && p2_gold < 100)
            std::cout << "Insufficient gold for training new units." << std::endl;
        if (units[1]->get_is_base_busy() == false && p2_gold > 100)
        {
            if (dice(1, 100) > 50)
                train(&dice, 'E', &p2_gold, units);
            else
                std::cout << "No training ordered." << std::endl;
        }

        /* ordering units to move */
        for (int i = 0; i < units.size(); i++)
            units[i]->move(&dice, 'E', map_size_x, map_size_y);

        player2_round_counter++;
        sleep(2);
    }

    return 0;
}