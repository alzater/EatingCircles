/**
Attention!
This file has Oxygine initialization stuff.
If you just started you don't need to understand it exactly you could check it later.
You could start from example.cpp and example.h it has main functions being called from there
*/
#include "core/oxygine.h"
#include "Stage.h"
#include "DebugActor.h"
#include <cstdlib>
#include <ctime>
#include "example.h"



using namespace oxygine;

Color color(32, 32, 32, 255);

Color getNewColor(){
  srand(time(0));
  int chose = rand() % 3;
  int change = rand()%226 + 30;
  switch (chose){
  case 0: 
    int rgb = color.r;
    if(rgb < change)
      ++rgb;
    else
      --rgb;
    if(rgb > 255 || rgb < 0)
      rgb = 126;
    color.r = rgb;
    break;
  /*case 1: 
    if(color.g < change)
      ++color.g;
    else
      --color.g;
    if(color.g > 255 || color.g < 0)
      color.g = 126;
    break;
  case 2: 
    if(color.b < change)
      ++color.b;
    else
      --color.b;
    if(color.b > 255 || color.b < 0)
      color.b = 126;
    break;*/
  }
  
  return color;
}
  
  
//called each frame
int mainloop()
{
	example_update();
	//update our stage
	//update all actors. Actor::update would be called also for all children
	getStage()->update();
	
	if (core::beginRendering())
	{		
		Rect viewport(Point(0, 0), core::getDisplaySize());
		//render all actors. Actor::render would be called also for all children
                srand(time(0));
		getStage()->render(getNewColor(), viewport);

		core::swapDisplayBuffers();
	}
        getStage()->setColor(getNewColor() );

	//update internal components
	//all input events would be passed to Stage::instance.handleEvent
	//if done is true then User requests quit from app.
	bool done = core::update();

	return done ? 1 : 0;
}

//it is application entry point
void run()
{
	ObjectBase::__startTracingLeaks();

	//initialize Oxygine's internal stuff
	core::init_desc desc;

#if OXYGINE_SDL || OXYGINE_EMSCRIPTEN
	//we could setup initial window size on SDL builds
	desc.w = 960;
	desc.h = 640;
	//marmalade settings could be changed from emulator's menu
#endif


	example_preinit();
	core::init(&desc);


	//create Stage. Stage is a root node
	Stage::instance = new Stage(true);
	Point size = core::getDisplaySize();
	getStage()->setSize(size);

	//DebugActor is a helper actor node. It shows FPS, memory usage and other useful stuff
	DebugActor::show();
		
	//initialize this example stuff. see example.cpp
	example_init();

#ifdef EMSCRIPTEN
	/*
	if you build for Emscripten mainloop would be called automatically outside. 
	see emscripten_set_main_loop below
	*/	
	return;
#endif


	//here is main game loop
	while (1)
	{
		int done = mainloop();
		if (done)
			break;
	}
	//user wants to leave application...

	//lets dump all created objects into log
	//all created and not freed resources would be displayed
	ObjectBase::dumpCreatedObjects();

	//lets cleanup everything right now and call ObjectBase::dumpObjects() again
	//we need to free all allocated resources and delete all created actors
	//all actors/sprites are smart pointer objects and actually you don't need it remove them by hands
	//but now we want delete it by hands

	//check example.cpp
	example_destroy();


	//renderer.cleanup();

	/**releases all internal components and Stage*/
	core::release();

	//dump list should be empty now
	//we deleted everything and could be sure that there aren't any memory leaks
	ObjectBase::dumpCreatedObjects();

	ObjectBase::__stopTracingLeaks();
	//end
}

#ifdef __S3E__
int main(int argc, char* argv[])
{
	run();
	return 0;
}
#endif


#ifdef OXYGINE_SDL
#ifdef __MINGW32__
int WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	run();
	return 0;
}
#else
#include "SDL_main.h"
extern "C"
{
	int main(int argc, char* argv[])
	{
		run();
		return 0;
	}
};
#endif
#endif

#ifdef EMSCRIPTEN
#include <emscripten.h>

void one(){ mainloop(); }

int main(int argc, char* argv[])
{
	run();
	emscripten_set_main_loop(one, 0, 0);
	return 0;
}
#endif
