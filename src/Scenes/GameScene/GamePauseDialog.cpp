#include "GamePauseDialog.h"
#include "Transition.h"
#include "../../Controller.h"

GamePauseDialog::GamePauseDialog()
{
    _dialog = true;
    flow::TransitionMove::assign(this);

    _menu->addItem(std::string("GAME PAUSED"));
    _menu->addItem(std::string("RESUME"), [this](Event*){finish();});
    _menu->addItem(std::string("RESTART GAME"), [this](Event*){
            finish();
            Controller::getController()->changeScene(Scenes::CONTINUE_GAME_SCENE);
        });
    _menu->addItem(std::string("MAIN MENU"), [this](Event*){
            finish();
            Controller::getController()->changeScene(Scenes::MAIN_MENU_SCENE);
        });
}
