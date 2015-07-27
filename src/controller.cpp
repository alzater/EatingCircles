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
  menu = new Menu();
  showMenu();
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
	gameResources.free();
}

void Controller::showMenu(){
  menu->addItem(std::string("play"), CLOSURE(this, &Controller::onNewGame));
  menu->addItem(std::string("Exit"), CLOSURE(this, &Controller::onExit));
}

void Controller::onNewGame(Event* e)
{
  spTween t = menu->addTween(Actor::TweenAlpha(0), 1000);
  t->addEventListener(TweenEvent::DONE, CLOSURE(this, &Controller::gameWait3));
  //------------
  
  //--------------
  game = new Game(1);
	getStage()->addChild(game);

}

void Controller::gameWait3(Event* e){
  getStage()->removeChild(menu);
  menu = new Menu();
  menu->addItem(std::string("3"));
  menu->setAlpha(0);
  getStage()->addChild(menu);
  spTween t = menu->addTween(Actor::TweenAlpha(250), 1000, 1, true, 0);
  t->addEventListener(TweenEvent::DONE, CLOSURE(this, &Controller::gameWait2));
}

void Controller::gameWait2(Event* e){
  getStage()->removeChild(menu);
  menu = new Menu();
  menu->addItem(std::string("2"));
  menu->setAlpha(0);
  getStage()->addChild(menu);
  spTween t = menu->addTween(Actor::TweenAlpha(250), 1000, 1, true, 0);
  t->addEventListener(TweenEvent::DONE, CLOSURE(this, &Controller::gameWait1));
}

void Controller::gameWait1(Event* e){
  getStage()->removeChild(menu);
  menu = new Menu();
  menu->addItem(std::string("1"));
  menu->setAlpha(0);
  getStage()->addChild(menu);
  spTween t = menu->addTween(Actor::TweenAlpha(250), 1000, 1, true, 0);
  t->addEventListener(TweenEvent::DONE, CLOSURE(this, &Controller::gameWaitGO));
}
  
void Controller::gameWaitGO(Event* e){
  playing = true;
  getStage()->removeChild(menu);
  menu = new Menu();
  menu->addItem(std::string("GO"));
  menu->setAlpha(0);
  getStage()->addChild(menu);
  spTween t = menu->addTween(Actor::TweenAlpha(250), 1000, 1, true, 0);
  spTween t2 = menu->addTween(Actor::TweenScale(5), 1000, 1, true, 0);
}

void Controller::onExit(Event* e){
  exit = true;
}

void Controller::onFinishGame(Event* e){
  playing = false;
  spTween t = game->addTween(Actor::TweenAlpha(0), 2000);
  menu = new Menu();
  menu->addItem(std::string("Game over"));
  menu->addItem(std::string("new game"), CLOSURE(this, &Controller::onNewGame));
  menu->addItem(std::string("Exit"), CLOSURE(this, &Controller::onExit));
  getStage()->addChild(menu);
}

