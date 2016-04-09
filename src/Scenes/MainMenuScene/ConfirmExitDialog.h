#ifndef __CONFIRM_EXIT_DIALOG_H__
#define __CONFIRM_EXIT_DIALOG_H__

#include "oxygine-framework.h"
#include "flow/Scene.h"
#include "../../Controls/menu.h"

using namespace oxygine;

DECLARE_SMART(ConfirmExitDialog, spConfirmExitDialog);

class ConfirmExitDialog  : public flow::Scene
{
    public:
        ConfirmExitDialog();
    private:
        spActor _actor;
        spMenu _menu;
};

#endif
