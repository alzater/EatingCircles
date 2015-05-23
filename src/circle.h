#pragma once
#include "oxygine-framework.h"
#include <functional>
using namespace oxygine;

class Circle;

typedef oxygine::intrusive_ptr<Circle> spCircle;

class Circle : public Sprite{
public:
  Circle(int s, int x, int y, Color color);
  Circle(Vector2 vect);
  ~Circle();
  void accelerate(Vector2 ys, double time);
  double getSize();
  void eatCircle(spCircle& circle);
  Vector2 getCenter();
  bool is_in_rect(Vector2 start, Vector2 end);
private:
  void update_gui();
  double  size;
  Color color;
  Vector2 velocity;
  Vector2 position;
};

