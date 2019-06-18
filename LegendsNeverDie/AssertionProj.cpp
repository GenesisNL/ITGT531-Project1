// AssertionProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <map>
#include "CWGame.hpp"


int main()
{
  CWGame game;

  if (!game.init())
  {
    std::cout << "Some error inside initilization";
    return 0;
  }

  while (true) 
  {
    game.update();
  }

  game.destroy();


}
