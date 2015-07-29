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
  void move(Vector2 delt);
  double getSize();
  void eatCircle(spCircle& circle);
  Vector2 getCenter();
  Vector2 getVelocity();
  bool is_in_rect(Vector2 start, Vector2 end);
  void boost(); //from blue-mana
  void loseMass(); //from red-power
private:
  void update_gui();
  void setAbilitiesFromColor();
  double  size, delta_size;
  Color color;
  Vector2 velocity;
  Vector2 position;
  int mana, agility, power;
};

