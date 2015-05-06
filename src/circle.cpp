#include "oxygine-framework.h"
#include <functional>
#include "circle.h"
using namespace oxygine;

//it is our resources
//in real project you would have more than one Resources declarations. 
//It is important on mobile devices with limited memory and you would load/unload them

Circle::Circle(int s, int x, int y, Color color):
    velocity(0,0),
    size(s),
    position( Vector2(x, y) )
  {
  gui = new ColorRectSprite();
  gui->setWidth(size * 2);
  gui->setHeight(size * 2);
  gui->setColor(color);
  gui->setPosition(position - Vector2(size, size));
  gui->setInputEnabled(false);
  gui->setUserData(0);
}

Circle::Circle(Vector2 vect):
    velocity(0,0),
    size(rand() % 57 + 4),
    position( vect - Vector2(size, size) )
  {
  gui = new ColorRectSprite();
  gui->setWidth(size * 2);
  gui->setHeight(size * 2);
  gui->setColor(Color(rand()%226 + 30, rand() % 226 + 30, rand() % 226+ 30));
  gui->setPosition(position);
  gui->setInputEnabled(false);
  gui->setUserData(0);
}

Circle::~Circle(){
  gui->detach();
}

void Circle::yscor(Vector2 ys, double time){
  Vector2 delta(size, size);
  velocity += ys;
  position = position + velocity;
  gui->setPosition(position- delta);
  velocity.x -=  velocity.x/size;
  velocity.y -= velocity.y/size;
}

void Circle::update_gui(){
  gui->setWidth(size * 2);
  gui->setHeight(size * 2);
  gui->setColor(color);
}

spColorRectSprite Circle::getGui(){
  return gui;
}

Color Circle::getColor(){
  return gui->getColor();
}

double Circle::getSize(){
  return size;
}

void Circle::eatCircle(spCircle& circle){
    color.r = (color.r * size + circle->getColor().r * circle->getSize()) 
      / (size + circle->getSize());
    color.r = (color.g * size + circle->getColor().g * circle->getSize()) 
      / (size + circle->getSize());
    color.r = (color.b * size + circle->getColor().b * circle->getSize()) 
      / (size + circle->getSize());
    size += circle->size / size;
    update_gui();
}

Vector2 Circle::getPosition(){
  return position;
}

bool Circle::is_in_rect(Vector2 start, Vector2 end){
  if(position.x < start.x || position.x > end.y ||
     position.y < start.y || position.y > end.y) return false;
  else
    return true;
}
  

