#include "ConfirmDialog.h"
#include "Transition.h"
#include "../Controller.h"

ConfirmDialog::ConfirmDialog(std::string title, std::string button_name)
{
    _dialog = true;
    flow::TransitionMove::assign(this);


    _menu->addItem(title);
    _menu->addItem(std::string("Back"), [this](Event *e){
            finish();
        });
    _menu->addItem(button_name, [this](Event *e){
            finish();
        });
    spColorRectSprite btn = new ColorRectSprite();
    btn->setSize(300, 300);
    btn->attachTo(_scene);
    btn->setColor(Color(255,0, 0));

   btn->addEventListener(TouchEvent::CLICK, [ = ](Event* ev)
   {
        ((ColorRectSprite*)(ev->target.get()))->setColor(Color(0, 255, 0));
       finish();
   });
}
