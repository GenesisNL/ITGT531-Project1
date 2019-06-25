 

 
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

	while (true && !game.endGame())
	{
		 
		game.update();
	
		
	}

	
	game.destroy();
	return 0;

}
