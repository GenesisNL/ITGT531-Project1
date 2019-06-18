 
#include "Map.hpp"

#include <iostream>

Map::Map():
  width(5), height(5)
{
}

Map::Map(unsigned int w, unsigned int h):
  width(w), height(h)
{
}

Map::~Map()
{
}

void Map::init()
{

}
void Map::update()
{
  std::cout << "|-----------------|" << std::endl;
  std::cout << "|.................|" << std::endl;
  std::cout << "|.................|" << std::endl;
  std::cout << "|.................|" << std::endl;
  std::cout << "|-----------------|" << std::endl;
}
void Map::detroy()
{

}