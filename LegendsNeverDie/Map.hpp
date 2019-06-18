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

private:
  unsigned int width;
  unsigned int height;
};

