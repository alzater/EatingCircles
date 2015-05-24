#include "oxygine-framework.h"
#include <functional>
#include "star.h"
#include <iostream>
using namespace oxygine;

//it is our resources
//in real project you would have more than one Resources declarations. 
//It is important on mobile devices with limited memory and you would load/unload them

static Resources gameResources;

Star::Star(Vector2 vect):
    position( vect )
  {
  setColor(Color(rand()%216 + 20, rand() % 216 + 20, rand() % 216 + 20));
  setPosition(position);
  setInputEnabled(false);
  setUserData(0);
}

Circle::~Circle(){
}

void init_bigstar(){
  setAnimFrame(gameResources.getResAnim("bigstar"));
  setScale(rand() % 5 + 4);
}

void init_littlestar(){
  getAnimFrame(gameResources.getResAnim("littlestar"));
  setScale(rand() % 5 + 2);
}

void init_pulstar(){
  getAnimFrame(gameResources.getResAnim("pulstar"));
  setScale(rand() % 5 + 2);
}

void Circle::move(Vector2 delt){
  velocity += ys;
  position = position + velocity;
  velocity.x -=  velocity.x * size2 / 250;
  velocity.y -= velocity.y * size2 / 250;
  setPosition(position);
}

void Circle::update_gui(){
  setScale(size/60);
  setColor(color);
}

double Circle::getSize(){
  return size;
}

Vector2 Circle::getVelocity(){
  return velocity;
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


Vector2 Circle::getCenter(){
  return position + Vector2(size,size);
}

bool Circle::is_in_rect(Vector2 start, Vector2 end){
  if(position.x < start.x || position.x > end.x ||
     position.y < start.y || position.y > end.y) return false;
  else
    return true;
}
  

