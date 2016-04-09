#ifndef __CONFIRM_NEW_GAME_DIALOG_H__
#define __CONFIRM_NEW_GAME_DIALOG_H__

#include "oxygine-framework.h"
#include "flow/Scene.h"
#include "../../Controls/menu.h"

using namespace oxygine;

DECLARE_SMART(ConfirmNewGameDialog, spConfirmNewGameDialog);

class ConfirmNewGameDialog : public flow::Scene
{
    public:
        ConfirmNewGameDialog();
    private:
        spActor _actor;
        spMenu _menu;
};

#endif
