#include "GameView.h"
#include "Gui/GuiController.h"

GameView::GameView()
{
    _background = new ColorRectSprite();
    _background->setColor(Color(240, 250, 240));
    addChild(_background);
}

GameView::~GameView()
{
    for(size_t i = 0; i < _objects.size(); ++i)
        _objects[i]->detach();
}

void GameView::addGuiObject()
{
    spGuiObject obj = GuiController::getGuiObject(1);
    //obj->setBot(spBot bot);
    _objects.push_back(obj);
}
