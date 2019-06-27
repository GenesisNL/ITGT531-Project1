#pragma once

#include <memory>
#include "json.hpp"

class Map;
class Player;
class Monster;
class Item;

class CWGame
{
public:
  CWGame();
  ~CWGame();
  //TODO: copy constructor and assignment operator

  bool init();
  void update();
  void destroy();
  void checkPos();
  void controller();
  bool endGame();
  void createMon();
  void createItem();
  void monsterCon();
  void dragonCon();
  

private:
  std::shared_ptr<Map> map;
  std::shared_ptr<Player> player;
  std::shared_ptr<Monster> monster;
  std::shared_ptr<Item> Sword;
  nlohmann::json jsonFile;


};


