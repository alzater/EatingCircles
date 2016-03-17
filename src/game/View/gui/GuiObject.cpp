#include "GuiObject.h"
#include <string>

extern Resources gameResources;

GuiObject::GuiObject(const Vector2& position, const double size, const Color& color)
{
    _gui = new Actor();
    _gui->setPosition(position);
    _previousPosition = position;
    _gui->setRotation(M_PI/2);
}

GuiObject::~GuiObject()
{}

void GuiObject::attachTo(spActor actor)
{
    actor->addChild(_gui);
}

void GuiObject::updateRotation(Vector2 newPos)
{
    Vector2 res = newPos - _previousPosition;
    if(res.x == 0 && res.y == 0)
        return;

    Vector2 oY = Vector2(1, 0);
    double skal_proizv = res.x * oY.x + res.y*oY.y;

    double modul = std::sqrt ( std::pow(res.x, 2) + std::pow( res.y, 2) ) *
        std::sqrt ( std::pow(oY.x, 2) + std::pow( oY.y, 2) );
    if(modul < 1e-15 && modul > -1e-15)
        return;

    double cosinus = skal_proizv/modul ;
    double gradus = acos(cosinus);
    if(res.y < 0){
        gradus += M_PI;
    }

    log::messageln(std::to_string(gradus).c_str());
    double oldAngle = _gui->getRotation();
    double newAngle = oldAngle - gradus;
    if(newAngle - oldAngle < -0.03)
        newAngle = oldAngle - 0.03;
    if(newAngle - oldAngle > 0.03)
        newAngle = oldAngle + 0.03;

    _gui->setRotation(newAngle);
    _previousPosition = newPos;
}
