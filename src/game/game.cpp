#include "oxygine-framework.h"
#include <functional>
#include "SDL.h"
#include "SDL_keyboard.h"

#include <ctime>
#include <cmath>
#include <iostream>
#include <cstdlib>

#include "game.h"
#include "circle.h"
#include "star.h"
#include "../controls/DTO.h"

using namespace oxygine;


Game::Game(int level, int gameStrategy):
  _level(level),
  _gameStrategy(gameStrategy),
  _score(0),
  _nBots(20),
  _nStars(20),
  _circles(_nBots),
  _stars(_nStars),
  _stageSize(core::getDisplaySize()),
  _nEated(0),
  _velocity(Vector2(0,0))
{
  _lastTime = getTimeMS();
  _maxMainSize = 71;
  _mainCircle = new Circle(30, _stageSize.x / 2, _stageSize.y / 2, genCircleColor());
  addChild(_mainCircle);
  srand(time(0));
  for(int i = 0; i < _nBots; ++i){
    _circles[i] = new Circle(rand() % (_nEated + 10), rand() % 1000, rand() % 1000, genCircleColor());
    addChild(_circles[i]);
  }
  for(int i = 0; i < _nStars; ++i){
    _stars[i] = new Star(Vector2(rand() % 1000, rand() % 1000));
    addChild(_stars[i]);
  }
}

int Game::nextFrame()
{
  if(!updateFrameTimeMultiplier())
    return 0;
  makeTurn();
  checkEaters();
  checkBotsPositions();
  if(!checkMainCircle())
    return 1; //game losed
  if(_mainCircle->getSize() > _maxMainSize)
    return 2; //level passed
  return 0;
}

void Game::makeTurn()
{
  for(int i = 0; i < _nBots; ++i){
    _circles[i]->makeLinerTurn();
  }
  mainCircleTurn();
}

void Game::mainCircleTurn()
{
  const Uint8* data  = SDL_GetKeyboardState(0);
  Vector2 displacement(0,0);
  
  if (data[SDL_SCANCODE_A] or data[SDL_SCANCODE_LEFT]) displacement.x = 1;
  if (data[SDL_SCANCODE_D] or data[SDL_SCANCODE_RIGHT]) displacement.x = -1;
  if (data[SDL_SCANCODE_W] or data[SDL_SCANCODE_UP]) displacement.y = 1;
  if (data[SDL_SCANCODE_S] or data[SDL_SCANCODE_DOWN]) displacement.y = -1;
  if (data[SDL_SCANCODE_SPACE]) _velocity *= 1.1;
  _velocity += displacement - _velocity * 0.04;
  
  for(int i = 0; i < _nBots; ++i)
  {
    _circles[i]->move(_velocity);
  }
  
  for(int i = 0; i < _nBots; ++i)
  {
    _stars[i]->move(_velocity * 0.1);
  }
  
  _mainCircle->loseMass();
}

bool Game::checkMainCircle()
{
  for(int i = 0; i < _nBots; ++i)
  {
    Vector2 mainCoords = _mainCircle->getCenter();
    Vector2 iCoords = _circles[i]->getCenter();
    double mainSize = _mainCircle->getSize();
    double iSize = _circles[i]->getSize();
    
    double distance = std::sqrt(std::pow(mainCoords.x - iCoords.x, 2) +
      std::pow(mainCoords.y - iCoords.y, 2) );
    getStage()->update();
    
    if(iSize + mainSize >= distance)
    {
      if(mainSize < iSize)
        return false;
        
      if(mainSize > iSize)
      {
        _mainCircle->eatCircle(_circles[i]);
        _circles[i]->reInitialize( getRandomCoords() );
        _nEated++;
      }
    }
  }
  return true;
}

void Game::checkEaters()
{
  for(int i = 1; i < _nBots; ++i)
  {
    for(int j = 0; j < i; ++j)
    {
      Vector2 jCoords = _circles[j]->getCenter();
      Vector2 iCoords = _circles[i]->getCenter();
      double jSize = _circles[j]->getSize();
      double iSize = _circles[i]->getSize();
      double distance = std::sqrt(std::pow(iCoords.x - jCoords.x, 2) +
        std::pow(iCoords.y - jCoords.y, 2) );
      
      if(iSize + jSize >= distance)
      {
        if(jSize < iSize)
        {
          _circles[i]->eatCircle(_circles[j]);
          _circles[j]->reInitialize( getRandomCoords() );
        }
        if(jSize > iSize)
        {
          _circles[j]->eatCircle(_circles[i]);
          _circles[i]->reInitialize( getRandomCoords() );
        }
      }
    }
  }
}

Vector2 Game::getRandomCoords()
{
  int x, y, sx = _stageSize.x, sy = _stageSize.y, division, tempX, tempY;

  division = rand() % 8;

  // 1 2 3
  // 0   4
  // 7 6 5
  
  const int EX = 400;
  const int EY = 400;
  const int ES = 100;
  
  switch( division )
  {
    case 0 :
      x = -(rand() % EX) - ES;
      y = rand() % sy;
      break;
    case 1 :
      x = -(rand() % EX) - ES;
      y = rand() % EY + sy + ES;
      break;
    case 2 :
      x = rand() % sx;
      y = rand() % EY + sy + ES;
      break;
    case 3 :
      x = rand() % EX + sx + ES;
      y = rand() % EY + sy + ES;
      break;
    case 4 :
      x = rand() % EX + sx + ES;
      y = rand() % sy;
      break;
    case 5 :
      x = rand() % EX + sx + ES;
      y = -(rand() % EY) - ES;
      break;
    case 6 :
      x = rand() % sx;
      y = -(rand() % EY) - ES;
      break;
    case 7 :
      x = -(rand() % EX) - ES;
      y = -(rand() % EY) - ES;    
  }
  
  return Vector2((float)x, (float)y);
}

void Game::checkBotsPositions()
{
  for(int i = 0; i < _nBots; ++i)
  {
    if( !_circles[i]->isInRectangle( Vector2(-400, -400), 
        Vector2(_stageSize.x + 400, _stageSize.y + 400) ) )
    {
      _circles[i]->reInitialize(getRandomCoords());
    }
  }
}

Color Game::genCircleColor()
{
  return Color(rand() % 200 + 55, rand() % 200 + 55, rand() % 200 + 55);
}

Color Game::genStarColor()
{
  return genCircleColor();
}

GameResults Game::getResult()
{
  return GameResults(_level, _nEated, _score);
}

bool Game::updateFrameTimeMultiplier()
{
  timeMS newTime = getTimeMS();
  if(_lastTime == newTime)
    return false;

  timeMS deltaTime = newTime - _lastTime;
  _timeMultiplier = (double)deltaTime / 1000;
  _lastTime = newTime; 
  //std::cout << timeMultiplier << std::endl;
  return true;  
}

double Game::getFrameTimeMultiplier()
{
  return _timeMultiplier;
}
