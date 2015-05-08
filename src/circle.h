#pragma once
#include "oxygine-framework.h"
#include <functional>
using namespace oxygine;

class Circle;

typedef oxygine::intrusive_ptr<Circle> spCircle;

class Circle : public Actor{
public:
  Circle(int s, int x, int y, Color color);
  Circle(Vector2 vect);
  ~Circle();
  void yscor(Vector2 ys, double time);
  spSprite getGui();
  Color getColor();
  double getSize();
  void eatCircle(spCircle& circle);
  Vector2 getPosition();
  bool is_in_rect(Vector2 start, Vector2 end);
private:
  void update_gui();
  spSprite gui;
  double  size;
  Color color;
  Vector2 velocity;
  Vector2 position;
};

