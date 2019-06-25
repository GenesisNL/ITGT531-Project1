#pragma once

class Player
{
public:
  Player();
  ~Player();
  int HP;
  
  int posX;
  int posY;
  int posHPX;
  int posHPY;
   


  void setPosHP(int x, int y);
   
  void update();
  void updateHP();
 
  void DisplayStats();
  void DisplayHP();
};

