#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "oxygine-flow.h"
#include "../../Game/Presenter/GamePresenter.h"
#include "GamePauseDialog.h"

class GameScene : public flow::Scene, IGamePauseDialogContext
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

        void gameWait();

        //from IGamePauseDialogContext
        virtual void restartGame();
        virtual void finishGame();

        void onGameWait(Event *e);
        void onPause(Event* e);
};
DECLARE_SMART(GameScene, spGameScene)

#endif
