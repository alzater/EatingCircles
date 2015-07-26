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
    void showMenu();
    void onNewGame(Event* e);
    
    int playing;
    //hideMenu();
    //startGame();
    //showGameResult();
    //finishGame();
    //oxygine::intrusive_ptr<Game> spGame;
};
