#include "GamePresenter.h"

GamePresenter::GamePresenter(int level)
{
    _game = new Game(level);
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
