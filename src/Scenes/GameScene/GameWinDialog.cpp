#include "MainMenuScene.h"
#include "../Controller.h"

MainMenuScene::MainMenuScene()
{
    _menu->addItem(std::string("EATING CIRCLES"));
    _menu->addItem(std::string("NEW GAME"), [](Event *e){
            Controller::getController()->changeScene(Scenes::GAME_SCENE);
        });
    _menu->addItem(std::string("EXIT"), [](Event *e){
            core::requestQuit();
        });
}
