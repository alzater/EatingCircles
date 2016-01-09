#include "MenuSceneBase.h"

MenuSceneBase::MenuSceneBase()
{
    _scene = new Actor();
    _scene->attachTo(_holder);
    _menu = new Menu(Vector2(getStage()->getSize().x / 2, 200));
    _menu->addToActor(_scene);
}

MenuSceneBase::~MenuSceneBase()
{}
