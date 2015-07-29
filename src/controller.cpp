#include "oxygine-framework.h"
#include <functional>
#include "controller.h"
#include "game/game.h"
#include "controls/menu.h"
#include <iostream>
#include <string>
#include <iostream>
using namespace oxygine;

Resources gameResources;

spGame game;
spMenu menu;


Controller::Controller(){
  playing = false;
  exit = false;
  
}

void Controller::preinit(){
  
}

//called from entry_point.cpp
void Controller::init()
{
  menu = new Menu();
  showMenu();
  getStage()->addChild(menu);
}


//called each frame from entry_point.cpp
int Controller::update()
{
  int temp = 0;
  if (playing){
    temp = game->nextFrame();
    switch( temp ){
      case 1: 
        onLoseGame(NULL);
        break;
      case 2:
        onWinGame(NULL);
        break;
    }
  }
  return exit;
}

void Controller::destroy()
{
	gameResources.free();
}

void Controller::showMenu(){
  menu->addItem(std::string("play"), CLOSURE(this, &Controller::onNewGame));
  menu->addItem(std::string("Exit"), CLOSURE(this, &Controller::onExit));
}

void Controller::onNewGame(Event* e){
  nextLevel = 1;
  onNextLevel(NULL);
}

void Controller::onNextLevel(Event* e){
  spTween t = menu->addTween(Actor::TweenAlpha(0), 1000);
  secondsLeft = 3;
  t->addEventListener(TweenEvent::DONE, CLOSURE(this, &Controller::gameWait));
  game = new Game(1);
	getStage()->addChild(game);
}

void Controller::gameWait(Event* e){
  if(!secondsLeft)
    playing = true;
  getStage()->removeChild(menu);
  menu = new Menu();
  if(secondsLeft){
    char c[2];
    c[0] = (char)(secondsLeft + 48);
    c[1] = '\0';
    menu->addItem(std::string(c));
  }
  else
    menu->addItem(std::string("GO"));
  menu->setAlpha(0);
  getStage()->addChild(menu);
  spTween t = menu->addTween(Actor::TweenAlpha(250), 1000, 1, true, 0);
  if(!secondsLeft)
    spTween t2 = menu->addTween(Actor::TweenScale(5), 1000, 1, true, 0);
  if(secondsLeft)
    t->addEventListener(TweenEvent::DONE, CLOSURE(this, &Controller::gameWait));
  --secondsLeft;
}

void Controller::onExit(Event* e){
  exit = true;
}

void Controller::onLoseGame(Event* e){
  playing = false;
  spTween t = game->addTween(Actor::TweenAlpha(0), 2000);
  menu = new Menu();
  menu->addItem(std::string("Game over"));
  menu->addItem(std::string("new game"), CLOSURE(this, &Controller::onNewGame));
  menu->addItem(std::string("Exit"), CLOSURE(this, &Controller::onExit));
  getStage()->addChild(menu);
  nextLevel = 1;
}

void Controller::onWinGame(Event* e){
  playing = false;
  spTween t = game->addTween(Actor::TweenAlpha(0), 2000);
  menu = new Menu();
  menu->addItem(std::string("You win"));
  menu->addItem(std::string("next level"), CLOSURE(this, &Controller::onNextLevel));
  menu->addItem(std::string("reset game"), CLOSURE(this, &Controller::onNewGame));
  menu->addItem(std::string("Exit"), CLOSURE(this, &Controller::onExit));
  getStage()->addChild(menu);
  ++nextLevel;
}
