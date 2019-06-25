#pragma once


class Monster
{
public:
	Monster();
	~Monster();

	int posX;
	int posY;
	char Icon;
	int HP;

	void update();
	void setXY(int x, int y);
	void updateI(const char &Icon);
	void DisplayStats();
	void onDestroy(int HP);

 
	 
};

