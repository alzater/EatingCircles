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
  if( !gameResources.getUseLoadCounter() )
    gameResources.loadXML("res.xml");
  switch(rand() % 3){
    case 0:
      init_bigstar();
      break;
    case 1:
      init_littlestar();
      break;
    case 2:
      init_pulstar();
  }
}

Star::~Star(){
}

void Star::init_bigstar(){
  setAnimFrame(gameResources.getResAnim("bigstar"));
  setScale((double)(rand() % 5 + 4)/15);
}

void Star::init_littlestar(){
  setAnimFrame(gameResources.getResAnim("littlestar"));
  setScale((double)(rand() % 5 + 2)/ 20);
}

void Star::init_pulstar(){
  setAnimFrame(gameResources.getResAnim("pulstar"));
  setScale((double)(rand() % 3 + 4)/20);
  addTween( createTween(Actor::TweenScale(0.1, 0.1), 5000, -1, true));
  addTween( createTween(Actor::TweenRotation(getRotation() + (float)MATH_PI * 2), 10000, -1));
}

void Star::move(Vector2 delt){
  position = position + delt;
  setPosition(position);
}

bool Star::is_in_rect(Vector2 start, Vector2 end){
  if(position.x < start.x || position.x > end.x ||
     position.y < start.y || position.y > end.y) return false;
  else
    return true;
}
  

