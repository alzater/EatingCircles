#include "GuiObject.h"
#include <string>

extern Resources gameResources;

GuiObject::GuiObject(const Vector2& position, const double size, const Color& color)
{
    gui = new Actor();
    gui->setPosition(position);
}

GuiObject::~GuiObject()
{}

void GuiObject::addTo(spActor actor)
{
    actor->addChild(gui);
}
