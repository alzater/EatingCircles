#ifndef __GAME_PAUSE_DIALOG_H__
#define __GAME_PAUSE_DIALOG_H__

#include "../MenuSceneBase.h"

DECLARE_SMART(GamePauseDialog, spGamePauseDialog);

class IGamePauseDialogContext
{
    public:
        virtual void restartGame() = 0;
        virtual void finishGame() = 0;
};

class GamePauseDialog : public MenuSceneBase
{
    public:
        GamePauseDialog(IGamePauseDialogContext *context);
};

#endif
