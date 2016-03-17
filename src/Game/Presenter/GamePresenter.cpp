#include "GamePresenter.h"
#include "../../Controller.h"

GamePresenter::GamePresenter()
{
    _game = new Game;
}

GamePresenter::~GamePresenter()
{
    Controller::getController()->removeGame(_game);
}

spActor GamePresenter::getView()
{
    return _view;
}

void GamePresenter::pauseGame()
{
    _game->pause();
}

void GamePresenter::resumeGame()
{
    _game->resume();
}
