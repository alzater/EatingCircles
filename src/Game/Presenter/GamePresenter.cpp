#include "GamePresenter.h"
#include "../../Controller.h"

GamePresenter::GamePresenter(int level)
{
    _game = new Game(level);
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
