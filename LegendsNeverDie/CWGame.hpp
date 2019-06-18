#pragma once

#include <memory>

class Map;
class Player;

class CWGame
{
public:
  CWGame();
  ~CWGame();
  //TODO: copy constructor and assignment operator

  bool init();
  void update();
  void destroy();

private:
  std::shared_ptr<Map> map;
  std::shared_ptr<Player> player;
};


