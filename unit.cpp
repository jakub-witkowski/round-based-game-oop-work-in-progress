#include <iostream>
#include "unit.h"

/* Updates the number of rounds before a training unit becomes fully functional */
void Unit::update_training_time(std::vector<Base*> b)
{
    if (this->training_time_left > 1)
        this->training_time_left--;
    else if (this->training_time_left == 1)
    {
        this->training_time_left--;
        if (this->affiliation == 'P')
        {
            b[0]->is_base_busy = false;
        }
        else if (this->affiliation == 'E')
        {
            b[1]->is_base_busy = false;
        }
    }
}

void Unit::move(int (*r)(int, int), char aff, int* u, const int x, const int y)
{
    if ((this->affiliation == aff) && (this->training_time_left == 0))
    {
        /* how many fields a unit is ordered to move in x and y direction */
        int x_axis_move;
        int y_axis_move;

        int row_number; // controls the use of the spread arrays
        bool dice_cast = false; // controls the validation process: 0 = no move generated; 1 = moves for two axes generated;
        int distance; // the distance the unit is attempting to cover
        int target_x; // target x coordinate
        int target_y; // target y coordinate

        /* auxiliary arrays for determining the x vs y spread in distance */
        const int spread1[2][2] = { {0, 1}, {1, 0} };
        const int spread2[3][2] = { {0, 2}, {1, 1}, {2, 0} };
        const int spread3[4][2] = { {0, 3}, {1, 2}, {2, 1}, {3, 0} };
        const int spread4[5][2] = { {0, 4}, {1, 3}, {2, 2}, {3, 1}, {4, 0} };
        const int spread5[6][2] = { {0, 5}, {1, 4}, {2, 3}, {3, 2}, {4, 1}, {5, 0} };

        if (this->type == 'K')
        {
            distance = r(0,6);
            switch (distance)
            {
                case 0:
                    x_axis_move = 0;
                    y_axis_move = 0;
                    dice_cast = false;
                    break;
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
        else if (this->type != 'K')
        {
            distance = r(0,2);
            switch (distance)
            {
                case 0:
                    x_axis_move = 0;
                    y_axis_move = 0;
                    dice_cast = false;
                    break;
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
            if (((this->x_coord + x_axis_move) >= x) || ((this->y_coord + y_axis_move) >= y))
                dice_cast = false; // cannot go outside the map
            if (distance > this->movement_points_left)
                dice_cast = false; // cannot exceed remaining movement
        }

        if (dice_cast == true)
        {
            target_x = this->x_coord + x_axis_move;
            target_y = this->y_coord + y_axis_move;
            this->movement_points_left -= distance;

            std::cout
            << "Ordering unit "
            << this->id
            << "to move to x: "
            << target_x
            << ", y: "
            << target_y
            << ". "
            << std::endl;

            this->x_coord = target_x;
            this->y_coord = target_y;
        }
    }
}