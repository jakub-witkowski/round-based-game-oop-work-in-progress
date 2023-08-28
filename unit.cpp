#include <iostream>
#include "unit.h"
#include "base.h"
#include "map.h"
#include <vector>

/* getter function definitions */
int Unit::get_number_of_active_units()
{
    return number_of_active_units;
}

char Unit::get_type()
{
    return this->type;
}
    
char Unit::get_affiliation()
{
    return this->affiliation;
}

int Unit::get_id()
{
    return this->id;
}

std::pair<int, int> Unit::get_coordinates()
{
    return this->coordinates;
}

int Unit::get_movement_points_left()
{
    return this->movement_points_left;
}

int Unit::get_current_stamina()
{
    return this->current_stamina;
}

bool Unit::get_can_attack_enemy_units()
{
    return this->can_attack_enemy_units;
}

int Unit::get_training_time_left()
{
    return this->training_time_left;
}

int Unit::get_cost()
{
    return this->cost;
}

int Unit::get_attack_range()
{
    return this->attack_range;
}
    
bool Unit::get_is_base_busy()
{
    return this->is_base_busy;
}

/* setter function definitions */
void Unit::set_type(char t)
{
    this->type = t;
}

void Unit::set_affiliation(char a)
{
    this->affiliation = a;
}

void Unit::set_id(int i)
{
    this->id = i;
}

void Unit::update_unit_counter(int c)
{
    number_of_active_units += c;
}

void Unit::set_coordinates(int x, int y)
{    
    this->coordinates.first = x;
    this->coordinates.second = y;
}

void Unit::set_current_stamina(int st)
{
    this->current_stamina = st;
}

void Unit::set_can_attack_enemy_units(bool choice)
{
    this->can_attack_enemy_units = choice;
}

void Unit::set_cost(int c)
{
    this->cost = c;
}

void Unit::set_movement_points_left(int dist)
{
    this->movement_points_left = dist;
}

void Unit::set_training_time_left(int t)
{
    this->training_time_left = t;
}

void Unit::decrease_training_time_left()
{
    this->training_time_left--;
}

void Unit::set_attack_range(int r)
{
    this->attack_range = r;
}

void Unit::set_is_base_busy(bool status)
{
    this->is_base_busy = status;
}

int Unit::number_of_active_units{0};

/* Updates the number of rounds before a training unit becomes fully functional */
void Unit::update_training_time(std::vector<Unit*> u, char aff)
{
    if (this->get_affiliation() == aff && this->get_training_time_left() > 1)
        this->decrease_training_time_left();
    else if (this->get_affiliation() == aff && this->get_training_time_left() == 1)
    {
        this->decrease_training_time_left();
        if (aff == 'P')
        {
            u[0]->set_is_base_busy(false);
        }
        else if (aff == 'E')
        {
            u[1]->set_is_base_busy(false);
        }
    }
}

/* Orders a unit to move to a randomly generated location */
void Unit::move(int (*r)(int, int), char aff, const int x, const int y, Map* m)
{
    if ((this->get_affiliation() == aff) && (this->get_training_time_left() == 0))
    {
        /* how many fields a unit is ordered to move in x and y direction */
        int x_axis_move{};
        int y_axis_move{};

        int row_number{}; // controls the use of the spread arrays
        bool dice_cast = false; // controls the validation process: 0 = no move generated; 1 = moves for two axes generated;
        int distance{}; // the distance the unit is attempting to cover
        int target_x{}; // target x coordinate
        int target_y{}; // target y coordinate

        /* auxiliary arrays for determining the x vs y spread in distance */
        const int spread1[2][2] = { {0, 1}, {1, 0} };
        const int spread2[3][2] = { {0, 2}, {1, 1}, {2, 0} };
        const int spread3[4][2] = { {0, 3}, {1, 2}, {2, 1}, {3, 0} };
        const int spread4[5][2] = { {0, 4}, {1, 3}, {2, 2}, {3, 1}, {4, 0} };
        const int spread5[6][2] = { {0, 5}, {1, 4}, {2, 3}, {3, 2}, {4, 1}, {5, 0} };

        if (this->get_type() == 'K')
        {
            distance = r(1,5);
            //distance = r(0,5);
            switch (distance)
            {
                /*case 0:
                    x_axis_move = 0;
                    y_axis_move = 0;
                    dice_cast = false;
                    break;*/
                case 1:
                    row_number = r(0,1);
                    x_axis_move = spread1[row_number][0];
                    y_axis_move = spread1[row_number][1];
                    dice_cast = true;
                    break;
                case 2:
                    row_number = r(0,2);
                    x_axis_move = spread2[row_number][0];
                    y_axis_move = spread2[row_number][1];
                    dice_cast = true;
                    break;
                case 3:
                    row_number = r(0,3);
                    x_axis_move = spread3[row_number][0];
                    y_axis_move = spread3[row_number][1];
                    dice_cast = true;
                    break;
                case 4:
                    row_number = r(0,4);
                    x_axis_move = spread4[row_number][0];
                    y_axis_move = spread4[row_number][1];
                    dice_cast = true;
                    break;
                case 5:
                    row_number = r(0,5);
                    x_axis_move = spread5[row_number][0];
                    y_axis_move = spread5[row_number][1];
                    dice_cast = true;
                    break;
            } 
        }
        else if (this->get_type() != 'K' && this->get_type() != 'B')
        {
            distance = r(1,2);
            //distance = r(0,2);
            switch (distance)
            {
                /*case 0:
                    x_axis_move = 0;
                    y_axis_move = 0;
                    dice_cast = false;
                    break;*/
                case 1:
                    row_number = r(0,1);
                    x_axis_move = spread1[row_number][0];
                    y_axis_move = spread1[row_number][1];
                    dice_cast = true;
                    break;
                case 2:
                    row_number = r(0,2);
                    x_axis_move = spread2[row_number][0];
                    y_axis_move = spread2[row_number][1];
                    dice_cast = true;
                    break;
            }
        }

        /* Validating target coordinates */
        if (dice_cast == true)
        {
            /* validating the draws against the map */
            if (this->get_affiliation() == 'P')
                if (((this->get_coordinates().first + x_axis_move) >= x) || ((this->get_coordinates().second + y_axis_move) >= y))
                    dice_cast = false; // cannot go outside the map
            if (this->get_affiliation() == 'E')
                if (((this->get_coordinates().first - x_axis_move) < 0) || ((this->get_coordinates().second - y_axis_move) < 0))
                    dice_cast = false; // cannot go outside the map
        }

        if (dice_cast == true)
        {
            if (distance > this->get_movement_points_left())
                dice_cast = false; // cannot exceed remaining movement
        }

        if (dice_cast == true)
        {
            if (this->get_affiliation() == 'P')
            {
                if (m->get_map_field_info(this->get_coordinates().first + x_axis_move, get_coordinates().second + y_axis_move) == 9)
                    dice_cast = false; // cannot go on natural obstacles
            }
            if (this->get_affiliation() == 'E')
            {
                if (m->get_map_field_info(this->get_coordinates().first - x_axis_move, get_coordinates().second - y_axis_move) == 9)
                    dice_cast = false; // cannot go on natural obstacles
            }
        }

        if (dice_cast == true)
        {
            if (this->get_affiliation() == 'P')
            {
                target_x = this->get_coordinates().first + x_axis_move;
                target_y = this->get_coordinates().second + y_axis_move;
            }
            else if (this->get_affiliation() == 'E')
            {
                target_x = this->get_coordinates().first - x_axis_move;
                target_y = this->get_coordinates().second - y_axis_move;
            }

            set_movement_points_left(get_movement_points_left() - distance);
            
            std::cout
            << "Ordering unit "
            << this->get_id()
            << " to move to x: "
            << target_x
            << ", y: "
            << target_y
            << ". "
            << std::endl;
    
            this->set_coordinates(target_x, target_y);
        }
    }
}