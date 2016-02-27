#include "Circle.h"

extern Resources gameResources;

Circle::Circle(const Vector2& position, const double size, const Color& color):
    GuiObject(position)
{
    _circle = new Sprite();
    _gui->addChild(_circle);
    _circle->setAnimFrame(gameResources.getResAnim("circle"));
    _circle->setAnchor(Vector2(0.5, 0.5));

    update(position, size, color);

    //spColorRectSprite crs = new ColorRectSprite();
    //crs->setColor(Color(255,0,0));
    //gui->addChild(crs);
    //crs->setSize(Vector2(50, 50));
}

Circle::~Circle()
{
}

void Circle::update(const Vector2& position, const double size, const Color& color)
{
    _gui->setPosition(position);
    _circle->setScale(size / 60);
    _circle->setColor(color);
}
