#include <iostream>
#include <vector>

/* Header files defining classes */
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

long gold{2000};
int units_on_the_map_counter{0};

int main()
{
    /* Declaring the vector to hold bases data */
    std::vector<Base*> bases = {new Base('P', &units_on_the_map_counter), new Base('E', &units_on_the_map_counter)};

    /* Declaring the vector to hold unit data */
    std::vector<Unit*> units;

    units.push_back(new Knight('P', &gold, &units_on_the_map_counter));
    units.push_back(new Swordsman('E', &gold, &units_on_the_map_counter));

    //std::cout << "Id of the unit under index 1: " << units[1]->id << std::endl;

    return 0;
}