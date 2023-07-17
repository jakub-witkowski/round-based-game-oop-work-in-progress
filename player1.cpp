#include <iostream>
#include "unit.h"
#include "base.h"
#include "knight.h"
#include "map_size.h"

int units_on_the_map_counter = 0;

int main()
{
    Base * unit_0 = new Base('P', &units_on_the_map_counter);
    Base * unit_1 = new Base('E', &units_on_the_map_counter);
    Knight * unit_2 = new Knight('P', &units_on_the_map_counter);

    return 0;
}