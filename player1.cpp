#include <iostream>
#include <vector>

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

/* header files including function definitions */
#include "train.h"

long gold{2000};
int units_on_the_map_counter{0};

int main()
{
    /* Declaring the vector to hold bases data */
    std::vector<Base*> bases = {new Base('P', &units_on_the_map_counter), new Base('E', &units_on_the_map_counter)};

    /* checking conditions for training a new unit; casting dice if the conditions are satisfied */
    if (bases[0]->is_base_busy != 0)
        std::cout << "Training in progress, cannot train new units." << std::endl;
    if (bases[0]->is_base_busy == 0 && gold < 100)
        std::cout << "Insufficient gold for training new units." << std::endl;
    if (bases[0]->is_base_busy == 0 && gold > 100)
    {
        if ((rand() % 100 + 1) > 50)
            train(&gold);
        else
            std::cout << "No training ordered." << std::endl;
    }

    /* Declaring the vector to hold unit data */
    std::vector<Unit*> units;

    units.push_back(new Knight('P', &gold, &units_on_the_map_counter));
    units.push_back(new Swordsman('E', &gold, &units_on_the_map_counter));

    //std::cout << "Id of the unit under index 1: " << units[1]->id << std::endl;

    return 0;
}