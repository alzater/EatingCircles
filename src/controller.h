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
    void onNextLevel(Event* e);
    void onExit(Event* e);
    void onLoseGame(Event* e);
    void onWinGame(Event* e);
    void gameWait(Event* e);
    void removeGameFromStage(Event* e);
    void removeMenuFromStage(Event* e);
    
    bool playing, exit;
    int secondsLeft, nextLevel;
    //hideMenu();
    //startGame();
    //showGameResult();
    //finishGame();
    //oxygine::intrusive_ptr<Game> spGame;
};
