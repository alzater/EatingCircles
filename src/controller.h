#pragma once
#include "oxygine-framework.h"
#include <functional>

using namespace oxygine;

class Controller{
  public:
    void preinit();
    void init();
    void destroy();
    int update();
    Controller();
  private:
    showMenu();
    hideMenu();
    startGame();
    showGameResult();
    finishGame();
    
    Resources gameResources;
    oxygine::intrusive_ptr<Game> spGame;
}
