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

void example_preinit(){
        
}

//called from entry_point.cpp
void example_init()
{
	spMainActor actor = new MainActor;

	//and add it to Stage as child
	getStage()->addChild(actor);

}


//called each frame from entry_point.cpp	
int example_update()
{
        game->nextFrame();
}

void example_destroy()
{
	//free previously loaded resources
	gameResources.free();
}
