#include "oxygine-framework.h"
#include <functional>

#include <iostream>

#include "circle.h"

using namespace oxygine;


static Resources gameResources;

Circle::Circle(int s, int x, int y, Color color):
    size_(s)
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
  randomInitialize();
}

void Circle::randomInitialize()
{
  size_ = rand() % 57 + 4;
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
  setScale(size_/60);
  lostSize_ = 0;
  velocity = Vector2(0,0);
}

Circle::~Circle()
{
}

void Circle::accelerate(Vector2 acceleration, double time)
{
  velocity += acceleration / 2;
  setPosition( getPosition() + velocity );
  velocity.x -=  velocity.x * size_ / 250;
  velocity.y -= velocity.y * size_ / 250;
}

void Circle::move(Vector2 deltaPosition)
{
  setPosition( getPosition() + deltaPosition );
}

void Circle::updateGui()
{
  setScale(size_ / 60);
}

double Circle::getSize()
{
  return size_;
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
  
  color.r = (color.r * size_ + cColor.r * cSize) / (size_ + cSize);
  color.g = (color.g * size_ + cColor.g * cSize) / (size_ + cSize);
  color.b = (color.b * size_ + cColor.b * cSize) / (size_ + cSize);
  size_ += cSize / size_;
  
  setColor(color);
  updateGui();
}


Vector2 Circle::getCenter()
{
  return getPosition() + Vector2(size_, size_);
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
  double changeSize = size_ * ((double)( 200 - getPower() )) / 2000000.0;
  lostSize_ += changeSize;
  size_ -= changeSize;
  
  if(lostSize_ > 0.5){
    lostSize_ = 0;
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
