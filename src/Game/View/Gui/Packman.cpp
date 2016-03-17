#include "Packman.h"

extern Resources gameResources;

Packman::Packman(const Vector2& position, const double size, const Color& color):
    GuiObject(position)
{
    _packman = new Sprite();
    _gui->addChild(_packman);
    _packman->setAnimFrame(gameResources.getResAnim("packman"));
    _packman->setAnchor(Vector2(0.5, 0.5));
    _packman->addTween(TweenAnim(gameResources.getResAnim("packman")), 1000, 0, true);


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
    _gui->setPosition(position);
    _packman->setScale(size / 60);
    _packman->setColor(color);
    updateRotation(position);
}
