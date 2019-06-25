#pragma once
class Map
{
public:
  Map();
  Map(unsigned int w, unsigned int h);
  ~Map();

  void init();
  void update();
  void detroy();

  void readMap();
 

  unsigned int width;
  unsigned int height;

private:
	

  char** maps;
 /* std::shared_ptr<Map> m_width;
  std::shared_ptr<Map> m_height;
  */

};

