#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "oxygine-framework.h"
#include "flow.h"

#include "game/Game.h"
#include "controls/menu.h"

#include "scenes/MainMenuScene.h"
#include "scenes/GameScene.h"

using namespace oxygine;

class Controller{
  public:
    static Controller& getController()
    {
      if (_instance == NULL) _instance = new Controller();
      return *_instance;
    }

    void preinit();
    void init();
    void destroy();
    int update();

    static void setGame(spGame game);
    static void removeGame();

  private:
    Controller();
    static Controller* _instance;

    spGameScene _gameScene;
    spMainMenuScene _mainMenuScene;

    spTextField _item;
    static spGame _game;



    bool exit;
    int nextLevel;
};

#endif
