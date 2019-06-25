 
#include "Map.hpp"

#include <iostream>
#include <fstream>
#include <string>

 

Map::Map():
	width(width), height(height)
{
	/**maps = reinterpret_cast<char*>(malloc(width * sizeof(char)));
	for (int i = 0; i < height; i++) {
		maps[i] = reinterpret_cast<char*>(malloc(height * sizeof(char)));
	}*/
}

Map::Map(unsigned int w, unsigned int h):
	width(w), height(h)
{
	/**maps = reinterpret_cast<char*>(malloc(width * sizeof(char)));
	for (int i = 0; i < height; i++) {
		maps[i] = reinterpret_cast<char*>(malloc(height * sizeof(char)));
	}*/
}

Map::~Map()
{
	
	for (int i = 0; i < height; i++) {
		 
			free(maps[i]);
		 
	}
	free(maps);

}

void Map::init()
{
	Map::readMap();
}
void Map::update()
{
	
	for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < width; j++) {
			std::cout << maps[i][j];
		}
		std::cout << std::endl;
	}
 

}

void Map::detroy()
{

}

void Map::readMap()
	 
{
	 
	std::string readLine;
	std::ifstream mapFile;
	mapFile.open("map.txt", std::ios::in | std::ios::app);
	 
	if (mapFile.is_open()) {
		std::getline(mapFile, readLine);
		maps = reinterpret_cast<char**>(malloc(std::stoi(readLine) * sizeof(char*)));
		height = std::stoi(readLine);
		std::cout<< std::endl << "\n\n\t Map" ;
		std::cout << " Height : " << std::stoi(readLine);

		std::getline(mapFile, readLine);
		for (unsigned int i = 0; i < height; i++) {
			maps[i] = reinterpret_cast<char*>(malloc(std::stoi(readLine) * sizeof(char)));
		}
		width = std::stoi(readLine);
		std::cout << " Width : " << std::stoi(readLine) << std::endl;
		int count = 0;
		while (std::getline(mapFile, readLine)) {
			for (size_t i = 0; i < readLine.length(); i++) {
				maps[count][i] = readLine.at(i);
			}
			count++;
		}
	}

	mapFile.close();



	
}