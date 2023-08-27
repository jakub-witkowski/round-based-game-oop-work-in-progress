#include <iostream>
#include <fstream>
#include "map.h"

#include <string>

constexpr int Map::line_count(std::string f)
{
    std::string line;
	int line_count{0};

	std::ifstream input(f);   

	if(input.is_open()) 
	{
		while(input.peek()!=EOF)
		{
			getline(input, line);
			line_count++;
		}
		input.close();
	}
 
	return line_count;
}

constexpr int Map::col_count(std::string f)
{
    std::string line;
	int col_count{0};

	std::ifstream input(f);   

	if(input.is_open()) 
	{
		getline(input, line);
		col_count = line.length();		
	}

	input.close();
 
	return col_count;
}

void Map::load_map_data(std::string fname)
{

}

bool Map::can_move_to(int x, int y)
{

}