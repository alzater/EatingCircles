#pragma once
#include "oxygine-framework.h"
#include <functional>
#include "circle.h"
#include "Polygon.h"
#include "star.h"
#include <vector>
#include "../controls/DTO.h"

using namespace oxygine;

class Game: public Actor{
  public:
    Game(int level, int gameStrategy = 0);
    int nextFrame();
    GameResults getResult();
    double getFrameTimeMultiplier();
  private:
    int _level, _score, _nBots, _nEated, _nStars, _maxMainSize;
    int _gameStrategy;
    Vector2 _velocity;
    Vector2 _stageSize;
    spCircle _mainCircle;
    std::vector <spCircle> _circles;
    std::vector <spStar> _stars;
    timeMS _lastTime;
    double _timeMultiplier;
    
    Vector2 getRandomCoords();
    void mainCircleTurn();
    void makeTurn();
    bool checkMainCircle();
    void checkBotsPositions();
    void checkEaters();
    Color genCircleColor();
    Color genStarColor();
    bool updateFrameTimeMultiplier();
    
    //---game strategy----
    void gameBeginer();
    void gameEasy();
    void gameMedium();
    void gameHard();
    void gameUltraHard();    
};

typedef oxygine::intrusive_ptr <Game> spGame;
