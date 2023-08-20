#ifndef UNIT_H
#define UNIT_H

#include <vector>

class Unit
{
    private:
    static int number_of_active_units;
 
    char type;
    char affiliation;
    int id;
    std::pair<int, int> coordinates;
    int movement_points_left; 
    int current_stamina;
    bool can_attack_enemy_units;
    int training_time_left;
    int cost;
    int attack_range;
    bool is_base_busy;

    public:

    /* getter function declarations */
    int get_number_of_active_units();

    char get_type();
    
    char get_affiliation();

    int get_id();

    std::pair<int, int> get_coordinates();

    int get_movement_points_left();

    int get_current_stamina();

    bool get_can_attack_enemy_units();

    int get_training_time_left();

    int get_cost();

    int get_attack_range();
    
    bool get_is_base_busy();

    /* setter function declarations */
    void set_type(char);

    void set_affiliation(char);

    void set_id(int);

    void update_unit_counter(int);

    void set_coordinates(int, int);

    void set_current_stamina(int);

    void set_can_attack_enemy_units(bool);

    void set_cost(int);

    void set_movement_points_left(int);

    void set_training_time_left(int);

    void set_attack_range(int);

    void set_is_base_busy(bool);

    /* other member functions */
    void update_training_time(std::vector<Unit*>);

    void move(int (*)(int, int), char, const int, const int);

    void attack();
};

#endif