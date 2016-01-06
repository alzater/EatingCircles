#include "Packman.h"

Packman::Packman(const Vector2& position, const double size, const Color& color):
    GuiObject(position)
{
  if( !gameResources.getUseLoadCounter() )
    gameResources.loadXML("res.xml");

    packman = new Sprite();
    gui->addChild(packman);
    packman->setAnimFrame(gameResources.getResAnim("packman"));
    packman->setAnchor(Vector2(0.5, 0.5));
    packman->addTween(TweenAnim(gameResources.getResAnim("packman")), 1000, 0, true);


    update(position, size, color);

    //spColorRectSprite crs = new ColorRectSprite();
    //crs->setColor(Color(255,0,0));
    //gui->addChild(crs);
    //crs->setSize(Vector2(50, 50));
}

Packman::~Packman()
{
}

void Packman::update(const Vector2& position, const double size, const Color& color)
{
    gui->setPosition(position);
    packman->setScale(size / 60);
    packman->setColor(color);
}

