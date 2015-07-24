#pragma once
#include "oxygine-framework.h"
#include <functional>
#include "game/game.h"

using namespace oxygine;

class Controller{
  public:
    void preinit();
    void init();
    void destroy();
    int update();
    Controller();
  private:
    //showMenu();
    //hideMenu();
    //startGame();
    //showGameResult();
    //finishGame();
    
    //oxygine::intrusive_ptr<Game> spGame;
};
