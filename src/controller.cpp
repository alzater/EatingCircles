#include "oxygine-framework.h"
#include <functional>
#include "math/vector2.h"
#include "ColorRectSprite.h"
#include "circle.h"
#include "game.h"
using namespace oxygine;

//it is our resources
//in real project you would have more than one Resources declarations. 
//It is important on mobile devices with limited memory and you would load/unload them




Controller::Controller(){
    spGame = new Game(1);
}

void Controller::preinit(){
        
}

//called from entry_point.cpp
void Controller::init()
{
	//and add it to Stage as child
	getStage()->addChild(spGame);
}


//called each frame from entry_point.cpp	
int Controller::update()
{
    return !spGame->nextFrame();
}

void Controller::destroy()
{
	//free previously loaded resources
	gameResources.free();
}




