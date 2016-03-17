#ifndef __GAME_PRESENTER_H__
#define __GAME_PRESENTER_H__

#include "oxygine-framework.h"

#include "../Model/Game.h"

using oxygine::EventDispatcher;

class GamePresenter : public EventDispatcher
{
public:
    GamePresenter();
    ~GamePresenter();

    spActor getView();

    void pauseGame();
    void resumeGame();
private:
    spGame _game;
    spActor _view;
};

DECLARE_SMART(GamePresenter, spGamePresenter)

#endif
