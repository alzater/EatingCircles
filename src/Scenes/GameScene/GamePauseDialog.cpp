#include "GamePauseDialog.h"
#include "flow/Transition.h"
#include "../../Controller.h"

GamePauseDialog::GamePauseDialog(IGamePauseDialogContext *context)
{
    _dialog = true;
    flow::TransitionMove::assign(this);

    _menu->addItem(std::string("GAME PAUSED"));
    _menu->addItem(std::string("RESUME"), [this](Event*){finish();});
    _menu->addItem(std::string("RESTART GAME"), [context](Event*){
        context->restartGame();
    });
    _menu->addItem(std::string("MAIN MENU"), [this](Event*){
        finish();
    });
}
