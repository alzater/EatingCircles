#ifndef __CONFIRM_DIALOG_H__
#define __CONFIRM_DIALOG_H__

#include "MenuSceneBase.h"

DECLARE_SMART(ConfirmDialog, spConfirmDialog);

class ConfirmDialog : public MenuSceneBase
{
    public:
        ConfirmDialog(std::string title, std::string button_name);
};

#endif
