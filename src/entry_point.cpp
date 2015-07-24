/**
Attention!
This file has Oxygine initialization stuff.
If you just started you don't need to understand it exactly you could check it later.
You could start from example.cpp and example.h it has main functions being called from there
*/
#include "core/oxygine.h"
#include "Stage.h"
#include "DebugActor.h"

#include "controller.h"



using namespace oxygine;

Color clearColor(255, 255, 255, 255);
Controller* controller;

Color update_color(){
  static int frame;
  return clearColor;
  ++frame;
  if(!frame) 
    return clearColor;
  
  int chose = rand() % 3, change = rand() % 2, color;
  if( !change )
    --change;

  switch( chose ){
    case 0:
      color = clearColor.r;
      break;
    case 1:
      color = clearColor.g;
      break;
    case 2:
      color = clearColor.b;
  }
  
  color += change * 5;
  if(color > 255 || color < 0)
    color = 125;
  
  switch( chose ){
    case 0:
      clearColor.r = color;
      break;
    case 1:
      clearColor.g = color;
      break;
    case 2:
      clearColor.b = color;
  }
  return clearColor;
}

//called each frame
int mainloop()
{
	bool done = controller->update();
	//update our stage
	//update all actors. Actor::update would be called also for all children
	getStage()->update();
	
	if (core::beginRendering())
	{		
		
		Rect viewport(Point(0, 0), core::getDisplaySize());
		//render all actors. Actor::render would be called also for all children
		getStage()->render(update_color(), viewport);

		core::swapDisplayBuffers();
	}

	//update internal components
	//all input events would be passed to Stage::instance.handleEvent
	//if done is true then User requests quit from app.
	if(!done)
          done= core::update();

	return done ? 1 : 0;
}

//it is application entry point
void run()
{
        controller = new Controller();
	ObjectBase::__startTracingLeaks();

	//initialize Oxygine's internal stuff
	core::init_desc desc;

#if OXYGINE_SDL || OXYGINE_EMSCRIPTEN
	//we could setup initial window size on SDL builds
	desc.w = 960;
	desc.h = 640;
	//marmalade settings could be changed from emulator's menu
#endif


	controller->preinit();
	core::init(&desc);


	//create Stage. Stage is a root node
	Stage::instance = new Stage(true);
	Point size = core::getDisplaySize();
	getStage()->setSize(size);

	//DebugActor is a helper actor node. It shows FPS, memory usage and other useful stuff
	DebugActor::show();
		
	//initialize this example stuff. see example.cpp
	controller->init();

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
	controller->destroy();


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




