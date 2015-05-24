#pragma once
#include "oxygine-framework.h"
#include <functional>
using namespace oxygine;

class Star;

typedef oxygine::intrusive_ptr<Star> spStar;

class Star : public Sprite{
public:
  Circle(Vector2 vect);
  ~Circle();
  void move(Vector2 delt);
  bool is_in_rect(Vector2 start, Vector2 end);
private:
  void init_bigstar();
  void init_littlestar();
  void init_pulstar();
  double  size;
  Color color;
  Vector2 position;
};

