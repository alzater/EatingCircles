#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "Scene.h"
#include "../../Game/Presenter/GamePresenter.h"
#include "GamePauseDialog.h"

DECLARE_SMART(GameScene, spGameScene)

class GameScene : public flow::Scene
{
    public:
        GameScene();
        virtual ~GameScene();

    private:
        bool _playing;
        int _secondsLeft;

        spActor _sceneView;
        spTextField _gameWaitTimer;
        spGamePresenter _gamePresenter;

        spGamePauseDialog _gamePauseDialog;

        void onGameWait(Event *e);
        void onPause(Event* e);
};

#endif
