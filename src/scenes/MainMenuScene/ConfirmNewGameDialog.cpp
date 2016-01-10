#include "ConfirmNewGameDialog.h"
#include "Transition.h"
#include "../../Controller.h"

extern Resources gameResources;

ConfirmNewGameDialog::ConfirmNewGameDialog()
{
    _dialog = true;
    flow::TransitionMove::assign(this);

    _actor = new Actor();
    _actor->attachTo(_holder);
    _menu = new Menu(Vector2(getStage()->getSize().x / 2, 200));
    _menu->addToActor(_actor);

    _menu->addItem(std::string("DO YOU REALY WANT TO START NEW GAME?\nYOU'LL LOSE YOUR PROGRESS!"));
    _menu->addItem(std::string("NEW GAME"), [this](Event*){
            finish();
            Controller::getController()->changeScene(Scenes::NEW_GAME_SCENE);
        });
    _menu->addItem(std::string("BACK"), [this](Event*){
            finish();
        });
}
