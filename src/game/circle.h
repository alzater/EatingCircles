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
  void reinit(Vector2 vect);
  void rand_init();
  void all_init();
  ~Circle();
  void loseMass(); //from red-power
  void accelerate(Vector2 ys, double time);
  void move(Vector2 delt);
  double getSize();
  void eatCircle(spCircle& circle);
  Vector2 getCenter();
  Vector2 getVelocity();
  bool is_in_rect(Vector2 start, Vector2 end);
  
  void make_rand_turn();
  void make_line_turn(float delt = 0);
  void make_intel_turn(const std::vector<spCircle>& circle, const float& stupid = 0);
  
private:
  void update_gui();
  void boost(); //from blue-mana
  void setAbilitiesFromColor();
  double  size, delta_size;
  Color color;
  Vector2 velocity;
  Vector2 position;
  int mana, agility, power;
};

