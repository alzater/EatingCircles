#pragma once
#include "oxygine-framework.h"
#include <functional>
#include "circle.h"

using namespace oxygine;

class Main_circle: public Circle{
public:
  Main_circle(int x, int y);
  void keyPressed(Event* event);  
};
