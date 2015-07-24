#include "oxygine-framework.h"
#include <functional>
#include "controller.h"
#include "game/game.h"
#include <iostream>
using namespace oxygine;

//it is our resources
//in real project you would have more than one Resources declarations. 
//It is important on mobile devices with limited memory and you would load/unload them
Resources gameResources;
Game* game;


class MainActor: public Actor
{
        
public:
	MainActor()
	{
                game = new Game(1);
	}
};

//declare spMainActor as intrusive_ptr holder of MainActor
typedef oxygine::intrusive_ptr<MainActor> spMainActor;


Controller::Controller(){
   
}

void Controller::preinit(){
        
}

//called from entry_point.cpp
void Controller::init()
{
    spMainActor actor = new MainActor;
	//and add it to Stage as child
	getStage()->addChild(actor);
}


//called each frame from entry_point.cpp	
int Controller::update()
{
    return !game->nextFrame();
}

void Controller::destroy()
{
	//free previously loaded resources
	gameResources.free();
}




