 

#include "CWGame.hpp"
#include <iostream>
#include <conio.h>

#include "Map.hpp"
#include "Player.h"

CWGame::CWGame()
  :map(std::make_shared<Map>()),
  player(std::make_shared<Player>())
{

}

CWGame::~CWGame()
{

}

bool CWGame::init()
{
  // initialized other systems

  map->init();
  player->posX = 2;
  player->posY = 2;

  return true;
}

void CWGame::update()
{
  char key = _getch();
  if (key == 'a')
  {
    player->posX--;
  }
  else if (key == 'd')
  {
    player->posX++;
  }
  else if (key == 'w')
  {
	  player->posY--;
  }
  else if (key == 's')
  {
	  player->posY++;
  }


  system("cls");

  map->update();
  player->update();

}

void CWGame::destroy()
{
  map->detroy();
}
