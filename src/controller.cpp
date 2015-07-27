#include "oxygine-framework.h"
#include <functional>
#include "controller.h"
#include "game/game.h"
#include "controls/menu.h"
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
  //game = new Game(1);
  menu = new Menu();
  menu->setPosition(getStage()->getSize() / 2);
  showMenu();
	//and add it to Stage as child
  getStage()->addChild(menu);
}


//called each frame from entry_point.cpp	
int Controller::update()
{
  bool temp = true;
  if (playing)
    temp = game->nextFrame();
  if(!temp)
    onFinishGame(NULL);
  return exit;
}

void Controller::destroy()
{
	//free previously loaded resources
	gameResources.free();
}

void Controller::showMenu(){
  menu->addItem(std::string("play"), CLOSURE(this, &Controller::onNewGame));
  menu->addItem(std::string("Exit"), CLOSURE(this, &Controller::onExit));
}

void Controller::onNewGame(Event* e)
{
  spTween t = menu->addTween(Actor::TweenAlpha(0), 1000);
  game = new Game(1);
	getStage()->addChild(game);
  playing = true;
}

void Controller::onExit(Event* e){
  exit = true;
}

void Controller::onFinishGame(Event* e){
  playing = false;
  spTween t = game->addTween(Actor::TweenAlpha(0), 2000);
  menu = new Menu();
  menu->setPosition(getStage()->getSize() / 2);
  menu->addItem(std::string("Game over"));
  menu->addItem(std::string("new game"), CLOSURE(this, &Controller::onNewGame));
  menu->addItem(std::string("Exit"), CLOSURE(this, &Controller::onExit));
  getStage()->addChild(menu);
}
