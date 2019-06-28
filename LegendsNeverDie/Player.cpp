 
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

void Player::updateHP()
{
	posHPX = 26;
	posHPY = 1;
	setPosHP(posHPX, posHPY);
	

	std::cout <<"Hero HP:"<< HP<<std::endl<< std::endl<< std::endl<< std::endl;

}


 

void Player::DisplayStats() 
{
	std::cout << "\n\n\t---Welcome to Legends never die game---";
	std::cout << "\n\n\t---Each time player move your health will be decress ---";
	std::cout << "\n\n\t---D=Dragon(You will die If you have no Legendary sword) ---";
	std::cout << "\n\n\t---G=Goblin(If it hit you you hp will decress If you have no Legendary sword)---";
	std::cout << "\n\n\t---L=Legendary sword can defeat every monster and get a health back---";
	std::cout << "\n\n\t---R= Red Potion you will get the health from it---";
	std::cout << "\n\n\t---Please Go to Hospital(H) immedieatly before run out of health---";
	 std::cout << "\n\n\t-w to move up, a to move left,s to move down and d to move to right-";
}

void  Player::DisplayHP() {
	std::cout << "\n\t Your Health: " << HP;
}


void  Player::setPosHP(int x, int y)
{
	
	printf("%c[%d;%df", 0x1B, y, x);

}
 
