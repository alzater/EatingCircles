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
  if (playing)
    return !game->nextFrame();
    return 0;
}

void Controller::destroy()
{
	//free previously loaded resources
	gameResources.free();
}

void Controller::showMenu(){
        menu->addItem(std::string("play"), CLOSURE(this, &Controller::onNewGame));
}

void Controller::onNewGame(Event* e)
{
        spTween t = menu->addTween(Actor::TweenAlpha(0), 1000);
        getStage()->removeChild(menu);
        game = new Game(1);
	getStage()->addChild(menu);
        playing = true;
}
