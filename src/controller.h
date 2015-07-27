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
    void onExit(Event* e);
    void onFinishGame(Event* e);
    
    //void gameWait(int i);
    
    void gameWait3(Event* e);
    void gameWait2(Event* e);
    void gameWait1(Event* e);
    void gameWaitGO(Event* e);
    
    bool playing, exit;
    //hideMenu();
    //startGame();
    //showGameResult();
    //finishGame();
    //oxygine::intrusive_ptr<Game> spGame;
};
