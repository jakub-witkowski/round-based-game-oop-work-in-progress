#include <iostream>
#include <vector>
#include <fstream>

/* class definitions */
#include "base.h"
#include "unit.h"
#include "knight.h"
#include "swordsman.h"
#include "catapult.h"
#include "archer.h"
#include "pikeman.h"
#include "worker.h"
#include "ram.h"

void train(int (*r)(int min, int max), char aff, long* g, int* u)
{
    int value{}; // holds the drawing result;
	std::string phrase; // phrase printed once training is initiated;
	bool choice_made = false; // controls the selection process;

	/* variables holding values that are saved in files once training is initiated */
	int unit_cost;
	char type;

    if (choice_made == false && *g < 200)
	{
		phrase = "training a worker";

		Worker* training_unit_ptr = new Worker(aff, g, u);

		unit_cost = training_unit_ptr->cost;
		type = training_unit_ptr->type;
		choice_made = true;
	}

    if (choice_made == false && (*g >= 100 && *g < 250))
	{
		value = r(1, 100);
		if (value <= 50)
		{
			phrase = "training a worker";

			Worker* training_unit_ptr = new Worker(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (value > 50)
		{
			phrase = "training a pikeman";

			Pikeman* training_unit_ptr = new Pikeman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
	}

    if (choice_made == false && (*g >= 250 && *g < 400))
	{
		value = r(1, 100);
		if (value <= 25)
		{
			phrase = "training a worker";

			Worker* training_unit_ptr = new Worker(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (value > 25 && value <= 50)
		{
			phrase = "training a pikeman";

			Pikeman* training_unit_ptr = new Pikeman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (value > 50 && value < 75)
		{
			phrase = "training a swordsman";

			Swordsman* training_unit_ptr = new Swordsman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (value > 75 && value <= 100)
		{
			phrase = "training an archer";

			Archer* training_unit_ptr = new Archer(aff, g);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
	}

    if (choice_made == false && (*g >= 400 && *g < 500))
	{
		value = r(1, 100);
		if (value <= 20)
		{
			phrase = "training a worker";

			Worker* training_unit_ptr = new Worker(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (value > 20 && value <= 40)
		{
			phrase = "training a pikeman";

			Pikeman* training_unit_ptr = new Pikeman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (value > 40 && value <= 60)
		{
			phrase = "training a swordsman";

			Swordsman* training_unit_ptr = new Swordsman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (value > 60 && value <= 80)
		{
			phrase = "training an archer";

			Archer* training_unit_ptr = new Archer(aff, g);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (value > 80 && value <= 100)
		{
			phrase = "training a knight";

			Knight* training_unit_ptr = new Knight(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
	}

	if (choice_made == false && (*g >= 500 && *g < 800))
	{
		value = r(1, 100);
		if ((3 * value) <= 50)
		{
			phrase = "training a worker";

			Worker* training_unit_ptr = new Worker(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((3 * value) > 50 && (3 * value) <= 100)
		{
			phrase = "training a pikeman";

			Pikeman* training_unit_ptr = new Pikeman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((3 * value) > 100 && (3 * value) <= 150)
		{
			phrase = "training a swordsman";

			Swordsman* training_unit_ptr = new Swordsman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((3 * value) > 150 && (3 * value) <= 200)
		{
			phrase = "training an archer";

			Archer* training_unit_ptr = new Archer(aff, g);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((3 * value) > 200 && (3 * value) <= 250)
		{
			phrase = "training a knight";

			Knight* training_unit_ptr = new Knight(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((3 * value) > 250 && (3 * value) <= 300)
		{
			phrase = "producing a ram";

			Ram* training_unit_ptr = new Ram(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
	}

	if (choice_made == false && *g > 800)
	{
		value = r(1, 100);
		if ((value * 3.5) <= 50)
		{
			phrase = "training a worker";

			Worker* training_unit_ptr = new Worker(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((value * 3.5) > 50 && (value * 3.5) <= 100)
		{
			phrase = "training a pikeman";

			Pikeman* training_unit_ptr = new Pikeman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((value * 3.5) > 100 && (value * 3.5) <= 150)
		{
			phrase = "training a swordsman";

			Swordsman* training_unit_ptr = new Swordsman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((value * 3.5) > 150 && (value * 3.5) <= 200)
		{
			phrase = "training an archer";

			Archer* training_unit_ptr = new Archer(aff, g);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((value * 3.5) > 200 && (value * 3.5) <= 250)
		{
			phrase = "training a knight";

			Knight* training_unit_ptr = new Knight(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((value * 3.5) > 250 && (value * 3.5) <= 300)
		{
			phrase = "producing a ram";

			Ram* training_unit_ptr = new Ram(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((value * 3.5) > 300)
		{
			phrase = "producing a catapult";

			Catapult* training_unit_ptr = new Catapult(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}	
	}
}

