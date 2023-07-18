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

long gold{2000};
int units_on_the_map_counter{0};

int main()
{
    Base* unit_0 = new Base('P', &units_on_the_map_counter);
    Base* unit_1 = new Base('E', &units_on_the_map_counter);
    Knight* unit_2 = new Knight('P', &gold, &units_on_the_map_counter);
    Swordsman* unit_3 = new Swordsman('E', &gold, &units_on_the_map_counter);
    Catapult* unit_4 = new Catapult('P', &gold, &units_on_the_map_counter);
    Worker* unit_5 = new Worker('E', &gold, &units_on_the_map_counter);
    Pikeman* unit_6 = new Pikeman('P', &gold, &units_on_the_map_counter);
    Archer* unit_7 = new Archer('E', &gold, &units_on_the_map_counter);
    Ram* unit_8 = new Ram('P', &gold, &units_on_the_map_counter);

    return 0;
}