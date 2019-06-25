#include "Monster.h"

#include <iostream>

Monster::Monster()
{

}

Monster::~Monster()
{

}

void Monster::setXY(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);

}

void Monster::update()
{
	
	setXY(posX, posY);
	 

	 
	 std::cout << "M";

}
 
void Monster::updateI(const char& Icon)
{

	setXY(posX, posY);
	 std::cout << Icon;
	 

}

void Monster::onDestroy(int HP) 
{
	if (HP = 0) {
		Icon = '.';
		//delete Icon;
	}

}

void Monster::DisplayStats()
{

	 

}