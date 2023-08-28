#include <iostream>
#include <fstream>
#include "map.h"

#include <string>

void Map::parse_map(std::string f, int n, int m[][map_size_x])
{
	std::string line;
	std::ifstream input(f);

	if(input.is_open()) 
	{
		for (int row = 0; row < n; row++)
		{
			getline(input, line);
			for (int col = 0; col < map_size_x; col++)
			{
				m[row][col] = line.at(col) - 48;
			};
		}

		input.close();
	}
	else
	{
		std::cout << "Could not parse " << f << "!" << std::endl;
	}

	
}

/*bool Map::can_move_to(int x, int y)
{

}*/