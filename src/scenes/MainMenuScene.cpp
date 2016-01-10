#include "MainMenuScene.h"
#include "ConfirmDialog.h"
#include "../Controller.h"

MainMenuScene::MainMenuScene()
{
    _menu->addItem(std::string("EATING CIRCLES"));
    _menu->addItem(std::string("NEW GAME"), [](Event *e){
            Controller::getController()->changeScene(Scenes::GAME_SCENE);
        });
    _menu->addItem(std::string("EXIT"), [](Event *e){
            std::string confirm("EXIT");
            spConfirmDialog dialog = new ConfirmDialog(std::string("REALY EXIT?"), confirm);
            flow::show(dialog, [=](Event* ev) {
                    if (ev->target->getName() == confirm)
                    {
                        core::requestQuit();
                    }
                });
        });
}
