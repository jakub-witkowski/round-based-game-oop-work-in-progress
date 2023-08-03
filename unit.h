#ifndef UNIT_H
#define UNIT_H

class Unit
{
    public:
    char type;
    char affiliation;
    int id;
    int x_coord;
    int y_coord;
    int movement_points_left; 
    int current_stamina;
    bool can_attack_enemy_units;
    int training_time_left;
    int cost;
    int attack_range;

    void move(int (*)(int, int), char, int*, const int, const int);

    void attack();
};

#endif