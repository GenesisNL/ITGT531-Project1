#include "Item.h"
 
#include <iostream>

Item::Item()
{

}


Item::~Item()
{

}

void Item::setXY(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);

}

void Item::update()
{

	setXY(posX, posY);
	 
	std::cout << "I";

}

void Item::updateI(const char &Icon)
{

	setXY(posX, posY);
	std::cout << Icon;


}

void  Item::onDestroy(int HP)
{
	if (HP = 0) {
		Icon = '.';
	}
}

 