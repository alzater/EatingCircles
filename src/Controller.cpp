#include "oxygine-framework.h"
#include <functional>

#include <iostream>
#include <string>
#include <sstream>

#include "Controller.h"
#include "Game/Model/Game.h"
#include "Controls/menu.h"

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
    flow::update();
    if(Controller::_game)
        Controller::_game->update();

    return exit;
}

void Controller::destroy()
{
    flow::free();
    gameResources.free();
}

void Controller::setGame(spGame game)
{
    _game = game;
}

void Controller::removeGame(spGame game)
{
    if(_game == game)
        _game = nullptr;
}

void Controller::changeScene(Scenes newScene)
{
    if(_gameScene)
        _gameScene->finish();
    _gameScene = nullptr;

    if(_mainMenuScene)
        _mainMenuScene->finish();
    _mainMenuScene = nullptr;

    switch(newScene)
    {
        case Scenes::CONTINUE_GAME_SCENE:
            _gameScene = new GameScene;
            flow::show(_gameScene);
            break;
        case Scenes::NEW_GAME_SCENE:
            _gameScene = new GameScene;
            flow::show(_gameScene);
            break;
        case Scenes::MAIN_MENU_SCENE:
            _mainMenuScene = new MainMenuScene;
            flow::show(_mainMenuScene);
            break;
    }
}

