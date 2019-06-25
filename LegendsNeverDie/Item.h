#pragma once

class Item
{
public:
	Item();
	~Item();
	int posX;
	int posY;
	int getSword;
	int HP;
	char Icon;

	void update();
	void updateI(const char &Icon);
	void setXY(int x, int y);
	void onDestroy(int HP);
};

