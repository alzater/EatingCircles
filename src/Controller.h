#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "oxygine-framework.h"
#include "flow/flow.h"

#include "Game/Model/Game.h"
#include "Controls/menu.h"

#include "Scenes/MainMenuScene/MainMenuScene.h"
#include "Scenes/GameScene/GameScene.h"

using namespace oxygine;

enum class Scenes {
    CONTINUE_GAME_SCENE,
    NEW_GAME_SCENE,
    MAIN_MENU_SCENE
};

class Controller{
  public:
    static Controller *getController();

    void preinit();
    void init();
    void destroy();
    int update();

    void setGame(spGame game);
    void removeGame(spGame game);

    void changeScene(Scenes newScene);

  private:
    static Controller *_instance;
    Controller();

    spGameScene _gameScene;
    spMainMenuScene _mainMenuScene;

    spTextField _item;
    spGame _game;

    bool exit;
    int nextLevel;
};

#endif
