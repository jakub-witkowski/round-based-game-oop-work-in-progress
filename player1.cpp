#include <iostream>
#include "unit.h"
#include "base.h"
#include "knight.h"
#include "swordsman.h"
#include "catapult.h"
#include "archer.h"
#include "pikeman.h"
#include "worker.h"
#include "ram.h"
#include "map_size.h"

int units_on_the_map_counter = 0;

int main()
{
    Base * unit_0 = new Base('P', &units_on_the_map_counter);
    Base * unit_1 = new Base('E', &units_on_the_map_counter);
    Knight * unit_2 = new Knight('P', &units_on_the_map_counter);
    Swordsman * unit_3 = new Swordsman('E', &units_on_the_map_counter);
    Catapult * unit_4 = new Catapult('P', &units_on_the_map_counter);
    Worker * unit_5 = new Worker('E', &units_on_the_map_counter);
    Pikeman * unit_6 = new Pikeman('P', &units_on_the_map_counter);
    Archer * unit_7 = new Archer('E', &units_on_the_map_counter);
    Ram * unit_8 = new Ram('P', &units_on_the_map_counter);

    return 0;
}