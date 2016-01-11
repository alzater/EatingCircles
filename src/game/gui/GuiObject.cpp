#include "GuiObject.h"
#include <string>

extern Resources gameResources;

GuiObject::GuiObject(const Vector2& position, const double size, const Color& color)
{
    _gui = new Actor();
    _gui->setPosition(position);
}

GuiObject::~GuiObject()
{}

void GuiObject::addChild(spActor actor)
{
    actor->addChild(_gui);
}
