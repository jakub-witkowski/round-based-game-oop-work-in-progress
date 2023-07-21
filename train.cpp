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

void train(int (*r)(), char aff, long* g, int* u, char* fname)
{
    //int value; // holds the drawing drawing result;
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
		if (r() <= 50)
		{
			phrase = "training a worker";

			Worker* training_unit_ptr = new Worker(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (r() > 50)
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
		if (r() <= 25)
		{
			phrase = "training a worker";

			Worker* training_unit_ptr = new Worker(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (r() > 25 && r() <= 50)
		{
			phrase = "training a pikeman";

			Pikeman* training_unit_ptr = new Pikeman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (r() > 50 && r() < 75)
		{
			phrase = "training a swordsman";

			Swordsman* training_unit_ptr = new Swordsman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (r() > 75 && r() <= 100)
		{
			phrase = "training an archer";

			Archer* training_unit_ptr = new Archer(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
	}

    if (choice_made == false && (*g >= 400 && *g < 500))
	{
		if (r() <= 20)
		{
			phrase = "training a worker";

			Worker* training_unit_ptr = new Worker(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (r() > 20 && r() <= 40)
		{
			phrase = "training a pikeman";

			Pikeman* training_unit_ptr = new Pikeman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (r() > 40 && r() <= 60)
		{
			phrase = "training a swordsman";

			Swordsman* training_unit_ptr = new Swordsman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (r() > 60 && r() <= 80)
		{
			phrase = "training an archer";

			Archer* training_unit_ptr = new Archer(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if (r() > 80 && r() <= 100)
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
		if ((r() + r() + r()) <= 50)
		{
			phrase = "training a worker";

			Worker* training_unit_ptr = new Worker(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() + r() + r()) > 50 && (r() + r() + r()) <= 100)
		{
			phrase = "training a pikeman";

			Pikeman* training_unit_ptr = new Pikeman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() + r() + r()) > 100 && (r() + r() + r()) <= 150)
		{
			phrase = "training a swordsman";

			Swordsman* training_unit_ptr = new Swordsman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() + r() + r()) > 150 && (r() + r() + r()) <= 200)
		{
			phrase = "training an archer";

			Archer* training_unit_ptr = new Archer(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() + r() + r()) > 200 && (r() + r() + r()) <= 250)
		{
			phrase = "training a knight";

			Knight* training_unit_ptr = new Knight(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() + r() + r()) > 250 && (r() + r() + r()) <= 300)
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
		if ((r() * 3.5) <= 50)
		{
			phrase = "training a worker";

			Worker* training_unit_ptr = new Worker(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() * 3.5) > 50 && (r() * 3.5) <= 100)
		{
			phrase = "training a pikeman";

			Pikeman* training_unit_ptr = new Pikeman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() * 3.5) > 100 && (r() * 3.5) <= 150)
		{
			phrase = "training a swordsman";

			Swordsman* training_unit_ptr = new Swordsman(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() * 3.5) > 150 && (r() * 3.5) <= 200)
		{
			phrase = "training an archer";

			Archer* training_unit_ptr = new Archer(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() * 3.5) > 200 && (r() * 3.5) <= 250)
		{
			phrase = "training a knight";

			Knight* training_unit_ptr = new Knight(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() * 3.5) > 250 && (r() * 3.5) <= 300)
		{
			phrase = "producing a ram";

			Ram* training_unit_ptr = new Ram(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}
		else if ((r() * 3.5) > 300)
		{
			phrase = "producing a catapult";

			Catapult* training_unit_ptr = new Catapult(aff, g, u);

			unit_cost = training_unit_ptr->cost;
			type = training_unit_ptr->type;
			choice_made = true;
		}	
	}
}

