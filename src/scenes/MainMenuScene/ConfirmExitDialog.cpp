#include "ConfirmExitDialog.h"
#include "Transition.h"

extern Resources gameResources;

ConfirmExitDialog::ConfirmExitDialog()
{
    _dialog = true;
    flow::TransitionMove::assign(this);

    _actor = new Actor();
    _actor->attachTo(_holder);
    _menu = new Menu(Vector2(getStage()->getSize().x / 2, 200));
    _menu->addToActor(_actor);

    _menu->addItem(std::string("REALY EXIT?"));
    _menu->addItem(std::string("EXIT"), [](Event*){
            core::requestQuit();
        });
    _menu->addItem(std::string("BACK"), [this](Event*){
            finish();
        });
}
