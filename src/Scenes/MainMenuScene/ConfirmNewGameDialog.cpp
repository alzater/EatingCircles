#include "ConfirmNewGameDialog.h"
#include "flow/Transition.h"
#include "../../Controller.h"

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
            flow::show(new GameScene);
        });
    _menu->addItem(std::string("BACK"), [this](Event*){
            finish();
        });
}
