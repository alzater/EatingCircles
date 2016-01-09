#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "oxygine-framework.h"
#include "flow.h"

#include "game/Game.h"
#include "controls/menu.h"

#include "scenes/MainMenuScene.h"
#include "scenes/GameScene.h"

using namespace oxygine;

enum class Scenes {GAME_SCENE, MAIN_MENU_SCENE};

class Controller{
  public:
    static Controller* getController();

    void preinit();
    void init();
    void destroy();
    int update();

    void setGame(spGame game);
    void removeGame();

    void changeScene(Scenes newScene);

  private:
    static Controller* _instance;
    Controller();

    spGameScene _gameScene;
    spMainMenuScene _mainMenuScene;

    spTextField _item;
    spGame _game;

    bool exit;
    int nextLevel;
};

#endif
