#include "MainMenuScene.h"
#include "../../Controller.h"
#include "ConfirmExitDialog.h"
#include "ConfirmNewGameDialog.h"

MainMenuScene::MainMenuScene()
{
    _scene = new Actor();
    _scene->attachTo(_holder);
    _menu = new Menu(Vector2(getStage()->getSize().x / 2, 200));
    _menu->addToActor(_scene);

    _menu->addItem(std::string("EATING CIRCLES"));
    _menu->addItem(std::string("CONTINUE"), [](Event*){
            flow::show(new GameScene);
        });
    _menu->addItem(std::string("NEW GAME"), [](Event*){
            spConfirmNewGameDialog dialog = new ConfirmNewGameDialog();
            flow::show(dialog);
        });
    _menu->addItem(std::string("EXIT"), [](Event*){
            spConfirmExitDialog dialog = new ConfirmExitDialog();
            flow::show(dialog);
        });
}
