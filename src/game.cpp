#include "oxygine-framework.h"
#include <functional>
#include "game.h"
#include "circle.h"
#include "star.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include "SDL.h"
#include "SDL_keyboard.h"

using namespace oxygine;



Game::Game(int l):
  level(l),
  score(0),
  num_of_bots(20),
  num_of_stars(20),
  circles(num_of_bots),
  stars(num_of_stars),
  stage_size(core::getDisplaySize()),
  eated(0)
{

  main_circle = new Circle(30, stage_size.x/2, stage_size.y/2, Color(255, 255, 255));
  getStage()->addChild(main_circle);
  srand(time(0));
  for(int i = 0; i < num_of_bots; ++i){
    circles[i] = new Circle(rand() % (eated + 10), rand() % 1000, rand() % 1000,
      Color(rand()%226 + 30, rand() % 226 + 30, rand() % 226+ 30));
    getStage()->addChild(circles[i]);
  }
  for(int i = 0; i < num_of_stars; ++i){
    stars[i] = new Star(Vector2(rand() % 1000, rand() % 1000));
    getStage()->addChild(stars[i]);
  }
}

bool Game::nextFrame(){
  make_turn();
  check_eaters();
  check_bots_positions();
  return check_main_circle();
}

void Game::make_turn(){
  for(int i = 0; i < num_of_bots; ++i){
    circles[i]->accelerate(Vector2(rand() % 3 - 1 , rand() % 3 - 1), 1.0/100);
  }
  main_circle_turn();
}

void Game::main_circle_turn(){
  const Uint8* data  = SDL_GetKeyboardState(0);
  Vector2 vec(0,0);
  if (data[SDL_SCANCODE_A] or data[SDL_SCANCODE_LEFT]) vec.x = 1;
  if (data[SDL_SCANCODE_D] or data[SDL_SCANCODE_RIGHT]) vec.x = -1;
  if (data[SDL_SCANCODE_W] or data[SDL_SCANCODE_UP]) vec.y = 1;
  if (data[SDL_SCANCODE_S] or data[SDL_SCANCODE_DOWN]) vec.y = -1;
  for(int i = 0; i < num_of_bots; ++i){
    circles[i]->accelerate(vec, 1.0/100, main_circle->getSize());
  }
  for(int i = 0; i < num_of_stars; ++i){
    stars[i]->move(vec);
  }
}

bool Game::check_main_circle(){
  for(int i = 0; i < num_of_bots; ++i){
    Vector2 main_coords = main_circle->getCenter();
    Vector2 coords_i = circles[i]->getCenter();
    double main_size = main_circle->getSize();
    double size_i = circles[i]->getSize();
    double distance = std::sqrt(std::pow(main_coords.x - coords_i.x, 2) +
      std::pow(main_coords.y - coords_i.y, 2) );
    getStage()->update();
    if(size_i + main_size >= distance){
      if(main_size < size_i)
        return false;
      if(main_size > size_i){
        main_circle->eatCircle(circles[i]);
        circles[i]->detach();
        circles[i] = new Circle( getRandomCoords() );
        getStage()->addChild(circles[i]);
        getStage()->update();
        ++eated;
      }
    }
  }
  return true;
}

void Game::check_eaters(){
  for(int i = 1; i < num_of_bots; ++i){
    for(int j = 0; j < i; ++j){
      Vector2 coords_j = circles[j]->getCenter();
      Vector2 coords_i = circles[i]->getCenter();
      double size_j = circles[j]->getSize();
      double size_i = circles[i]->getSize();
      double distance = std::sqrt(std::pow(coords_i.x - coords_j.x, 2) +
        std::pow(coords_i.y - coords_j.y, 2) );
      
      if(size_i + size_j >= distance){
        if(size_j < size_i){
          circles[i]->eatCircle(circles[j]);
          circles[j]->detach();
          circles[j] = new Circle( getRandomCoords() );
          getStage()->addChild(circles[j]);
          getStage()->update();
        }
        if(size_j > size_i){
          circles[j]->eatCircle(circles[i]);
          circles[i]->detach();
          circles[i] = new Circle( getRandomCoords() );
          getStage()->addChild(circles[i]);
          getStage()->update();
        }
      }
    }
  }
}

Vector2 Game::getRandomCoords(){
  int x, y, sx = stage_size.x, sy = stage_size.y, div;
  
  x = rand() % ( sx - 200) + 100;
  y = rand() % ( sy - 200) + 100;
  div = rand() % 8;
  
  /*switch( div ){
    case 0 :
      
      
    
    
  }*/
  
  
  if( x < sx - 100 ){
    x *= -1;
    x -= 100;
  }  else
    x += 200;
  
  y = rand() % ( sy * 2 - 200);
  if( y < sy - 100 ){
    y *= -1;
    y -= 100;
  }  else
    y += 200;
  
  return Vector2(x, y);
}

void Game::check_bots_positions(){
  for(int i = 0; i < num_of_bots; ++i){
    if( !circles[i]->is_in_rect( Vector2(-900, -900), 
        Vector2(stage_size.x+900, stage_size.y + 900) )
      ){
        renew_circle(circles[i]);
      }
  }
}

void Game::renew_circle(spCircle& circle){
  circle = new Circle( getRandomCoords() );
  getStage()->addChild(circle);
  getStage()->update();
}
