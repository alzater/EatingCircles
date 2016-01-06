#include "Circle.h"

Circle::Circle(const Vector2& position, const double size, const Color& color):
    GuiObject(position)
{
  if( !gameResources.getUseLoadCounter() )
    gameResources.loadXML("res.xml");

    circle = new Sprite();
    gui->addChild(circle);
    circle->setAnimFrame(gameResources.getResAnim("circle"));
    circle->setAnchor(Vector2(0.5, 0.5));

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
    gui->setPosition(position);
    circle->setScale(size / 60);
    circle->setColor(color);
}

