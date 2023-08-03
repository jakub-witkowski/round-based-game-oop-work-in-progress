#include <iostream>
#include <vector>
#include <random>

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

/* setting up random number generator 
#include "roll_dice.h"*/

/* function and function pointer declarations */
extern int dice(int, int);
/*using func_ptr = decltype(&dice);
func_ptr cast_dice = &dice;*/
extern void train(int (*r)(int min, int max), char aff, long* g, int* u);

long gold{2000}; // variable holding the current amount of gold
int units_on_the_map_counter{0}; // variable holding the current number of units present on the map

int main()
{
    /* Declaring the vector to hold bases data */
    std::vector<Base*> bases = {new Base('P', &units_on_the_map_counter), new Base('E', &units_on_the_map_counter)};

    /* checking conditions for training a new unit; rolling dice if the conditions are satisfied */
    if (bases[0]->is_base_busy != 0)
        std::cout << "Training in progress, cannot train new units." << std::endl;
    if (bases[0]->is_base_busy == 0 && gold < 100)
        std::cout << "Insufficient gold for training new units." << std::endl;
    if (bases[0]->is_base_busy == 0 && gold > 100)
    {
        if (dice(1, 100) > 50)
            train(&dice, bases[0]->affiliation, &gold, &units_on_the_map_counter);
        else
            std::cout << "No training ordered." << std::endl;
    }

    /* Declaring the vector to hold unit data 
    std::vector<Unit*> units;

    units.push_back(new Knight('P', &gold, &units_on_the_map_counter));
    units.push_back(new Swordsman('E', &gold, &units_on_the_map_counter));*/

    //std::cout << "Id of the unit under index 1: " << units[1]->id << std::endl;

    return 0;
}