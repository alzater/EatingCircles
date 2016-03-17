#include "oxygine-framework.h"
#include <functional>
#include "star.h"
#include <iostream>
using namespace oxygine;

//it is our resources
//in real project you would have more than one Resources declarations. 
//It is important on mobile devices with limited memory and you would load/unload them

extern Resources gameResources;

Star::Star(Vector2 position)
{
  setPosition(position);
  setColor( Color(rand() % 216 + 20, rand() % 216 + 20, rand() % 216 + 20) );
  setInputEnabled(false);
  setUserData(0);

  switch(rand() % 3){
    case 0:
      initializeBig();
      break;
    case 1:
      initializeLittle();
      break;
    case 2:
      initializePulsar();
  }
}

Star::~Star()
{
}

void Star::initializeBig()
{
  setAnimFrame(gameResources.getResAnim("bigstar"));
  setScale( (double)(rand() % 5 + 4) / 15 );
}

void Star::initializeLittle()
{
  setAnimFrame(gameResources.getResAnim("littlestar"));
  setScale( (double)(rand() % 5 + 2) / 20 );
}

void Star::initializePulsar()
{
  setAnimFrame(gameResources.getResAnim("pulstar"));
  setScale( (double)(rand() % 3 + 4) / 20 );
  addTween( createTween(Actor::TweenScale(0.1, 0.1), 5000, -1, true) );
  addTween( createTween( Actor::TweenRotation( getRotation() + (float)MATH_PI * 2 ), 10000, -1 ) );
}

void Star::move(Vector2 deltaPosition)
{
  setPosition( getPosition() + deltaPosition );
}

bool Star::isInRectangle(Vector2 start, Vector2 end)
{
  Vector2 currentPosition = getPosition();
  if( currentPosition.x < start.x || currentPosition.x > end.x ||
      currentPosition.y < start.y || currentPosition.y > end.y){
    return false;
  }
  else {
    return true;
  }
}
  

