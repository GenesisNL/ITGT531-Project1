 
#include "Player.h"
#include "utility.h"
#include <iostream>

Player::Player()
{
}


Player::~Player()
{
}

void Player::update()
{
  gotoxy(posX, posY);
  std::cout << "P";
}