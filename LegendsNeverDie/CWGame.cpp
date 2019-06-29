 

#include "CWGame.hpp"
#include <iostream>
#include <conio.h>
 
#include <fstream>
#include <string>

#include "Map.hpp"
#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include "json.hpp"


#define jsonFilename  "Gamesetting.json"
using json = nlohmann::json;

// to check which side of wall is 
int checkDWall = 0;
int checkGWall = 0;


CWGame::CWGame()
  :map(std::make_shared<Map>()),
     player(std::make_shared<Player>()),	
				Sword(std::make_shared<Item>()),
					monster(std::make_shared<Monster>())
			
{
	 

}
 


CWGame::~CWGame()
{
	
}

//create monster

Monster* Dragon = new Monster();
Monster* Goblin= new Monster();

//create Item
Item* Potion = new Item();
Item* LSword = new Item();
Item* HCP= new Item();
//create old player pos for dragon move
Player* OldPosP = new Player();
//create old player pos  for  gobline move
Player* OldPosP2 = new Player();

void CWGame::createMon() 

{
	if (Dragon->HP > 0)
	{
		

		Dragon->Icon = 'D';

		Dragon->updateI(Dragon->Icon);

	}

	if(Goblin->HP > 0){
	
	
	Goblin->Icon = 'G';
	Goblin->updateI(Goblin->Icon);
	}


}

void CWGame::createItem()

{

	if (Potion->HP > 0) {
		
		Potion->posX = static_cast<int>(jsonFile["item"]["Potion"]["posX"]);
		Potion->posY = static_cast<int>(jsonFile["item"]["Potion"]["posY"]);
		Potion->Icon = 'R';
		Potion->updateI(Potion->Icon);
	}

	if (LSword->HP > 0) {
		LSword->posX = static_cast<int>(jsonFile["item"]["LSword"]["posX"]);
		LSword->posY = static_cast<int>(jsonFile["item"]["LSword"]["posY"]);

		LSword->Icon = 'S';

		LSword->updateI(LSword->Icon);
	}
	 
	 
		HCP->posX = map->width-1;
		HCP->posY = map->height-1;

		HCP->Icon = 'H';

		HCP->updateI(HCP->Icon);
	 


}

 
bool CWGame::init()
{
	std::ifstream ifs(jsonFilename);
	jsonFile = json::parse(ifs);


	//set pos mon to interacty
	Dragon->posX = static_cast<int>(jsonFile["Monster"]["Dragon"]["posX"]);
	Dragon->posY = static_cast<int>(jsonFile["Monster"]["Dragon"]["posY"]);
 

	Goblin->posX = static_cast<int>(jsonFile["Monster"]["Goblin"]["posX"]);
	Goblin->posY = static_cast<int>(jsonFile["Monster"]["Goblin"]["posY"]);

	//set hp monster
	Goblin->HP = static_cast<int>(jsonFile["Monster"]["Goblin"]["HP"]);
	Dragon->HP = static_cast<int>(jsonFile["Monster"]["Dragon"]["HP"]);
	//set hp Item
	Potion->HP = static_cast<int>(jsonFile["item"]["Potion"]["HP"]);;
	LSword->HP = static_cast<int>(jsonFile["item"]["Lsword"]["HP"]);;
	 
	player->DisplayStats();
	map->init();

	player->posX = static_cast<int>(jsonFile["player"]["posX"]);
	player->posY = static_cast<int>(jsonFile["player"]["posY"]);

	// old player pos to make monster update
	OldPosP->posX = player->posX;
	OldPosP->posY = player->posY;
	OldPosP2->posX = player->posX;
	OldPosP2->posY = player->posY;

	player->HP = static_cast<int>(jsonFile["player"]["HP"]);
  


  //0=no 1=yes
  Sword->getSword = 0;
   
  

  return true;
}

void CWGame::checkPos()
{
	if (player->posX == Dragon->posX&& player->posY == Dragon->posY)
	{
		 
			if (Sword->getSword == 1) {

				if (Dragon->HP > 0) {

				
				std::cout << "Your defeat the dragon get 10extra health";
				player->HP = player->HP + 10;
				Dragon->HP = 0;
				Dragon->onDestroy(Dragon->HP);
				//delete Dragon;

				}
				else {

				}
			}
			 
			else{
			std::cout << "Fight with A Dragon Can't Fight your die";
			player->HP = player->HP -100;
			Dragon->HP = Dragon->HP - 1;
			 
		}
	}
	else if(player->posX == Goblin->posX&& player->posY == Goblin->posY)
	{
		 
			//check if player have sword
			if (Sword->getSword == 1) {
				if (Goblin->HP > 0) {
					std::cout << "Your defeat the Goblin get 5extra health";
					player->HP = player->HP + 5;
					Goblin->HP = 0;
					Goblin->posX = 1;
					Goblin->posY = 17;
					Goblin->onDestroy(Goblin->HP);
					//delete Goblin;
				}
				else {
				}
			}
			else{
			std::cout << "Fight with moster HP -10";
			player->HP = player->HP - 10;
			Goblin->HP = Goblin->HP - 2;

			 
		}
	}

	else if (player->posX == Potion->posX&& player->posY == Potion->posY)
	{
		 
			if (Potion->HP > 0) {

			
			std::cout << "Collect Red potion HP+10";
			Potion->HP = 0;
			Potion->onDestroy(Potion->HP);
			player->HP= player->HP +10;

			//delete Heart;

			}
			else {

			}

		 
	}
	 else if (player->posX == LSword->posX&& player->posY == LSword->posY)
	{
		 
			if (LSword->HP > 0) {

				std::cout << "Your get the legendary sword(Next Time fight with monster alway win)";
				LSword->HP = 0;
				LSword->onDestroy(LSword->HP);
				 
				//get sword = yes
				Sword->getSword = 1;
			}
			else {
			
			}
		 
	} 

	
}
bool CWGame::endGame() {

	if (player->HP <= 0) {
		for (int i = 0; i < map->height - 1; i++) {
			std::cout << "\n";

		}
		std::cout<< std::endl<< " --Game overs!--\n";
		 
		// pause the program
		system("pause");
		return true;
		//pause the do ?? vv
		 
	}
	else if (player->posX == HCP->posX&& player->posY == HCP->posY)
	{
		for (int i = 0; i < map->height - 1; i++) {
			std::cout << "\n";

		}
			std::cout << " **** You Win **** \n";
			std::cout << "You Score:"<<player->HP<<"\n";
			 system("pause");

			 return true;
 
	}

	else {
		return false;
	}

}

void CWGame::controller() {

	char key = _getch();
	if (key == 'a')
	{
		/*set if hit the wall or not*/
		/*if not hit can move */
		if (player->posX > 2) {
			player->posX--;
			player->HP --;
		 
		 
		}

		else  /*if hit then not move*/
		{
			player->posX = player->posX;
		 
			//update monter move here or anything
			
		}
 
	}
	else if (key == 'd')
	{
		if (player->posX <  map->width-1) 
		{
		player->posX++;
		player->HP --;
		}
	else {
		player->posX = player->posX;
	}
	
		 
	}
	else if (key == 'w')
	{
		if (player->posY > 2) {
			player->posY--;
			player->HP --;
		}
		else {
			player->posY = player->posY;
		}
		


	}
	else if (key == 's')
	{
				
		if (player->posY < map->height-1) {
			player->posY++;
			player->HP --;
		}
		else {
			player->posY = player->posY;
		}
		

	}
	//monster to move
	
	CWGame::dragonCon();
	CWGame::monsterCon();

	system("cls");
	
}



void CWGame::dragonCon() 

{
	

	if (OldPosP->posX != player->posX) 
	{
		/*check dragon not to hit a wall and move side to side*/
		if (Dragon->posX > 2 && Dragon->posX < map->width - 1) {
			

			if (checkDWall == 0) {
				Dragon->posX++;
			}
			else {
				Dragon->posX--;
			}
			
		}
		else if (Dragon->posX <= 2)  {
			 
			checkDWall = 0;

			if (checkDWall == 0) {
				Dragon->posX++;
			}
			else {
				Dragon->posX--;
			}
		}
		else if (Dragon->posX >= map->width - 1) {
			
			checkDWall = 1;

			if (checkDWall == 0) {
				Dragon->posX++;
			}
			else {
				Dragon->posX--;
			}
			 

			
		}


		OldPosP->posX = player->posX;
	}
	else if (OldPosP->posY != player->posY)
	{
		/*check dragon not to hit a wall and move side to side*/
		if (Dragon->posX > 2 && Dragon->posX < map->width - 1) {


			if (checkDWall == 0) {
				Dragon->posX++;
			}
			else {
				Dragon->posX--;
			}

		}
		else if (Dragon->posX <= 2) {

			checkDWall = 0;

			if (checkDWall == 0) {
				Dragon->posX++;
			}
			else {
				Dragon->posX--;
			}
		}
		else if (Dragon->posX >= map->width - 1) {

			checkDWall = 1;

			if (checkDWall == 0) {
				Dragon->posX++;
			}
			else {
				Dragon->posX--;
			}

		}

 
		OldPosP->posY = player->posY;
	}





}
 

void CWGame::monsterCon()

{

	if (OldPosP2->posX != player->posX)
	{
		/*check goblin not to hit a wall and move side to side*/
		if (Goblin->posY > 2 && Goblin->posY < map->height - 1) {


			if (checkGWall == 0) {
				Goblin->posY++;
			}
			else {
				Goblin->posY--;
			}

		}
		else if (Goblin->posY <= 2) {

			checkGWall = 0;

			if (checkGWall == 0) {
				Goblin->posY++;
			}
			else {
				Goblin->posY--;
			}
		}
		else if (Goblin->posY >= map->height - 1) {

			checkGWall = 1;

			if (checkGWall == 0) {
				Goblin->posY++;
			}
			else {
				Goblin->posY--;
			}

		}
		OldPosP2->posX = player->posX;
	}
	else if (OldPosP2->posY != player->posY)
	{
		/*check goblin not to hit a wall and move side to side*/
		if (Goblin->posY > 2 && Goblin->posY < map->height - 1) {


			if (checkGWall == 0) {
				Goblin->posY++;
			}
			else {
				Goblin->posY--;
			}

		}
		else if (Goblin->posY <= 2) {

			checkGWall = 0;

			if (checkGWall == 0) {
				Goblin->posY++;
			}
			else {
				Goblin->posY--;
			}
		}
		else if (Goblin->posY >= map->height - 1) {

			checkGWall = 1;

			if (checkGWall == 0) {
				Goblin->posY++;
			}
			else {
				Goblin->posY--;
			}

		}
		OldPosP2->posY = player->posY;





	}
 
}

void CWGame::update()
{
	 
	CWGame::endGame();
	for (int i = 0; i < map->height - 1; i++) {
		std::cout << "\n";

	}
	
	CWGame::checkPos();
	

	CWGame::controller();
	
  
  map->update();
  CWGame::createMon();
  CWGame::createItem();
  
 
 
  
  player->update();
  player->updateHP();
  

  //std::cout << player->HP;
 
}

void CWGame::destroy()
{

 map->detroy();

}
