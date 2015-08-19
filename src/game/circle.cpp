#include "oxygine-framework.h"
#include <functional>

#include <iostream>

#include "circle.h"

using namespace oxygine;


static Resources gameResources;

Circle::Circle(int s, int x, int y, Color color):
    _size(s)
{
  setPosition(Vector2(x, y));
  setColor(color);
  allInitialize();
}

Circle::Circle(Vector2 vect)
{
  setPosition(vect);
  randomInitialize();
}

void Circle::reInitialize(Vector2 vect)
{
  setPosition(vect);
  _size = rand() % 57 + 4;
  setColor( Color( rand() % 200 + 55, rand() % 200 + 55, rand() % 200 + 55) );
  setScale(_size/60);
  _lostSize = 0;
  velocity = Vector2(0,0);
}

void Circle::randomInitialize()
{
  _size = rand() % 57 + 4;
  setColor( Color( rand() % 200 + 55, rand() % 200 + 55, rand() % 200 + 55) );
  allInitialize();
}

void Circle::allInitialize()
{
  if( !gameResources.getUseLoadCounter() )
  {
    gameResources.loadXML("res.xml");
  }
  setInputEnabled(false);
  setUserData(0);
  setAnimFrame(gameResources.getResAnim("circle"));
  setScale(_size / 60);
  _lostSize = 0;
  velocity = Vector2(0,0);
}

Circle::~Circle()
{
}

void Circle::accelerate(Vector2 acceleration, double time)
{
  velocity += acceleration / 2;
  setPosition( getPosition() + velocity );
  velocity.x -=  velocity.x * _size / 250;
  velocity.y -= velocity.y * _size / 250;
}

void Circle::move(Vector2 deltaPosition)
{
  setPosition( getPosition() + deltaPosition );
}

void Circle::updateGui()
{
  setScale(_size / 60);
}

double Circle::getSize()
{
  return _size;
}

Vector2 Circle::getVelocity()
{
  return velocity;
}

void Circle::eatCircle(spCircle& circle)
{
  Color color = getColor();
  double cSize = circle->getSize();
  Color cColor = circle->getColor();
  
  color.r = (color.r * _size + cColor.r * cSize) / (_size + cSize);
  color.g = (color.g * _size + cColor.g * cSize) / (_size + cSize);
  color.b = (color.b * _size + cColor.b * cSize) / (_size + cSize);
  _size += cSize / _size;
  
  setColor(color);
  updateGui();
}


Vector2 Circle::getCenter()
{
  return getPosition() + Vector2(_size, _size);
}

bool Circle::isInRectangle(Vector2 start, Vector2 end)
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

void Circle::loseMass()
{
  double changeSize = _size * ((double)( 200 - getPower() )) / 2000000.0;
  _lostSize += changeSize;
  _size -= changeSize;
  
  if(_lostSize > 0.5){
    _lostSize = 0;
    updateGui();
  }
}

void Circle::boost()
{
  velocity *= 2;
}

void Circle::makeRandomTurn()
{
  accelerate(Vector2( rand() % 3 - 1 , rand() % 3 - 1 ), 1.0 / 100);
  loseMass();
}

void Circle::makeLinerTurn(float deviation)
{
  if(velocity.x == 0 && velocity.y == 0)
    makeRandomTurn();
    
  if(deviation < 0 || deviation > 1)
    deviation = 0;
    
  Vector2 result = velocity / std::sqrt( velocity.x * velocity.x + velocity.y * velocity.y );
  
  result.x += (rand() % 3 - 1) * deviation;
  if (result.x > 1)
    result.x = 1;
  if (result.x < -1)
    result.x = -1;
    
  result.y += (rand() % 3 - 1) * deviation;
  if (result.y > 1)
    result.y = 1;
  if (result.y < -1)
    result.y = -1;
    
  accelerate(result, 1.0 / 100);
  loseMass();
}

void Circle::makeIntellectualTurn(const std::vector <spCircle>& circle, float stupidity){
  
  
  loseMass();
}

int Circle::getPower()
{
  return getColor().r;
}

int Circle::getMana()
{
  return getColor().b;
}

int Circle::getAgility()
{
  return getColor().g;
}
