#include "oxygine-framework.h"
#include <functional>

#include <iostream>
#include <string>
#include <sstream>

#include "Controller.h"
#include "game/Game.h"
#include "controls/menu.h"

using namespace oxygine;

Resources gameResources;

Controller* Controller::_instance;

Controller* Controller::getController()
{
  if (_instance == NULL) _instance = new Controller();
  return _instance;
}

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
    changeScene(Scenes::MAIN_MENU_SCENE);

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

void Controller::changeScene(Scenes newScene)
{
    switch(newScene)
    {
        case Scenes::GAME_SCENE:
            _gameScene = new GameScene;
            flow::show(_gameScene, [this](Event *e){_gameScene = nullptr;});
            break;
        case Scenes::MAIN_MENU_SCENE:
            _mainMenuScene = new MainMenuScene;
            flow::show(_mainMenuScene, [this](Event *e){_mainMenuScene = nullptr;});
            break;
        default:
            flow::show(_mainMenuScene);
            break;
    }
}

