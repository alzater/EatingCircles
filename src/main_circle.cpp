#include "oxygine-framework.h"
#include <functional>
#include "main_circle.h"
#include "circle.h"

Main_circle::Main_circle(int x, int y):
    Circle(x, y)
{
  getStage()->addEventListener(KeyEvent::KEY_DOWN,  CLOSURE(this, &Main_circle::keyPressed));
}

void Main_circle::keyPressed(Event* event)
{
    KeyEvent* e = (KeyEvent*)event;
    if(e->data->keysym.sym == SDLK_DOWN)
            gui->setPosition(gui->getPosition() + Vector2(0, 5));
    if(e->data->keysym.sym == SDLK_UP)
            gui->setPosition(gui->getPosition() + Vector2(0, -5));
    if(e->data->keysym.sym == SDLK_LEFT)
            gui->setPosition(gui->getPosition() + Vector2(-5, 0));
    if(e->data->keysym.sym == SDLK_RIGHT)
            gui->setPosition(gui->getPosition() + Vector2(5, 0));
}
