#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "Scene.h"
#include "../../Game/Model/Game.h"
#include "GamePauseDialog.h"

DECLARE_SMART(GameScene, spGameScene);

class GameScene : public flow::Scene
{
    public:
        GameScene();
        virtual ~GameScene();

    private:
        void gameWait(Event *e);
        void onPause(Event* e);

        bool _playing;
        int _secondsLeft;

        spActor _view;
        spGame _game;
        spTextField _gameWaitTimer;

        spGamePauseDialog _gamePauseDialog;
};

#endif
