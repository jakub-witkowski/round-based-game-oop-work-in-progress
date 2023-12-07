#include <iostream>
#include <vector>
#include <functional>
//#include <fstream>

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

//void train(int (*r)(int min, int max), char aff, long* g, std::vector<Unit*>& u)
void train(std::function<int(int,int)> r, char aff, long* g, std::vector<Unit*>& u)
{
    int value{}; // holds the drawing result;
	std::string prefix{"Started "};
	std::string phrase; // phrase printed once training is initiated;
	bool choice_made = false; // controls the selection process;

	/* variables holding values that are saved in files once training is initiated */
	int unit_cost;
	char type;

    if (choice_made == false && *g < 200)
	{
		phrase = "training a worker";
		u.push_back(new Worker(aff, g));
		choice_made = true;

		/*Worker* training_unit_ptr = new Worker(aff, g);

		unit_cost = training_unit_ptr->get_cost();
		type = training_unit_ptr->get_type();*/
	}

    if (choice_made == false && (*g >= 100 && *g < 250))
	{
		value = r(1, 100);
		if (value <= 50)
		{
			phrase = "training a worker";
			u.push_back(new Worker(aff, g));
			choice_made = true;
		}
		else if (value > 50)
		{
			phrase = "training a pikeman";
			u.push_back(new Pikeman(aff, g));
			choice_made = true;
		}
	}

    if (choice_made == false && (*g >= 250 && *g < 400))
	{
		value = r(1, 100);
		if (value <= 25)
		{
			phrase = "training a worker";
			u.push_back(new Worker(aff, g));
			choice_made = true;
		}
		else if (value > 25 && value <= 50)
		{
			phrase = "training a pikeman";
			u.push_back(new Pikeman(aff, g));
			choice_made = true;
		}
		else if (value > 50 && value < 75)
		{
			phrase = "training a swordsman";
			u.push_back(new Swordsman(aff, g));
			choice_made = true;
		}
		else if (value > 75 && value <= 100)
		{
			phrase = "training an archer";
			u.push_back(new Archer(aff, g));
			choice_made = true;
		}
	}

    if (choice_made == false && (*g >= 400 && *g < 500))
	{
		value = r(1, 100);
		if (value <= 20)
		{
			phrase = "training a worker";
			u.push_back(new Worker(aff, g));
			choice_made = true;
		}
		else if (value > 20 && value <= 40)
		{
			phrase = "training a pikeman";
			u.push_back(new Pikeman(aff, g));
			choice_made = true;
		}
		else if (value > 40 && value <= 60)
		{
			phrase = "training a swordsman";
			u.push_back(new Swordsman(aff, g));
			choice_made = true;
		}
		else if (value > 60 && value <= 80)
		{
			phrase = "training an archer";
			u.push_back(new Archer(aff, g));
			choice_made = true;
		}
		else if (value > 80 && value <= 100)
		{
			phrase = "training a knight";
			u.push_back(new Knight(aff, g));
			choice_made = true;
		}
	}

	if (choice_made == false && (*g >= 500 && *g < 800))
	{
		value = r(1, 100);
		if ((3 * value) <= 50)
		{
			phrase = "training a worker";
			u.push_back(new Worker(aff, g));
			choice_made = true;
		}
		else if ((3 * value) > 50 && (3 * value) <= 100)
		{
			phrase = "training a pikeman";
			u.push_back(new Pikeman(aff, g));
			choice_made = true;
		}
		else if ((3 * value) > 100 && (3 * value) <= 150)
		{
			phrase = "training a swordsman";
			u.push_back(new Swordsman(aff, g));
			choice_made = true;
		}
		else if ((3 * value) > 150 && (3 * value) <= 200)
		{
			phrase = "training an archer";
			u.push_back(new Archer(aff, g));
			choice_made = true;
		}
		else if ((3 * value) > 200 && (3 * value) <= 250)
		{
			phrase = "training a knight";
			u.push_back(new Knight(aff, g));
			choice_made = true;
		}
		else if ((3 * value) > 250 && (3 * value) <= 300)
		{
			phrase = "producing a ram";
			u.push_back(new Ram(aff, g));
			choice_made = true;
		}
	}

	if (choice_made == false && *g > 800)
	{
		value = r(1, 100);
		if ((value * 3.5) <= 50)
		{
			phrase = "training a worker";
			u.push_back(new Worker(aff, g));
			choice_made = true;
		}
		else if ((value * 3.5) > 50 && (value * 3.5) <= 100)
		{
			phrase = "training a pikeman";
			u.push_back(new Pikeman(aff, g));
			choice_made = true;
		}
		else if ((value * 3.5) > 100 && (value * 3.5) <= 150)
		{
			phrase = "training a swordsman";
			u.push_back(new Swordsman(aff, g));
			choice_made = true;
		}
		else if ((value * 3.5) > 150 && (value * 3.5) <= 200)
		{
			phrase = "training an archer";
			u.push_back(new Archer(aff, g));
			choice_made = true;
		}
		else if ((value * 3.5) > 200 && (value * 3.5) <= 250)
		{
			phrase = "training a knight";
			u.push_back(new Knight(aff, g));
			choice_made = true;
		}
		else if ((value * 3.5) > 250 && (value * 3.5) <= 300)
		{
			phrase = "producing a ram";
			u.push_back(new Ram(aff, g));
			choice_made = true;
		}
		else if ((value * 3.5) > 300)
		{
			phrase = "producing a catapult";
			u.push_back(new Catapult(aff, g));
			choice_made = true;
		}	
	}

	if (choice_made == true)
	{
		if (aff == 'P')
		{	
			u[0]->set_is_base_busy(true);
			std::cout
			<< "Base 0 now busy."
			<< std::endl;
		}
		else if (aff == 'E')
		{
			u[1]->set_is_base_busy(true);
			std::cout
			<< "Base 1 now busy."
			<< std::endl;
		}

		std::cout
		<< std::endl
		<< prefix
		<< phrase << ". "
		<< " Units.size() = "
		<< u.size()
		<< std::endl;
	}

}

