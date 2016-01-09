#include "oxygine-framework.h"
#include <functional>

#include <iostream>
#include <string>
#include <sstream>

#include "controller.h"
#include "game/Game.h"
#include "controls/menu.h"

using namespace oxygine;

Resources gameResources;

spGame Controller::_game = nullptr;

Controller::Controller()
{
    exit = false;
}

void Controller::preinit()
{}

//called from entry_point.cpp
void Controller::init()
{
    gameResources.loadXML("res.xml");

    flow::init();
    _gameScene = new GameScene;
    _mainMenuScene = new MainMenuScene;
    flow::show(_gameScene);

    _item = new TextField();
    _item->setPosition(0, 600);
    getStage()->addChild(_item);
}


//called each frame from entry_point.cpp
int Controller::update()
{

    int temp = 0;

    if(Controller::_game)
        Controller::_game->nextFrame();

    return exit;
}

void Controller::destroy()
{
    gameResources.free();
}

void Controller::setGame(spGame game)
{
    Controller::_game = game;
}

void Controller::removeGame()
{
    Controller::_game = nullptr;
}
