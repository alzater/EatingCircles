#pragma once
#include "oxygine-framework.h"
#include <functional>
#include "Bot.h"
#include "Polygon.h"
#include "../View/ExtraObjects/star.h"
#include "AI.h"
#include <vector>
#include "../../Controls/DTO.h"

using namespace oxygine;

class Game : public Object
{
    public:
        Game(int gameStrategy = 0);
        int update();
        GameResults getResult();
        double getFrameTimeMultiplier();
        void pause();
        void resume();
    private:
        int _level, _score, _nBots, _nEated, _nStars, _maxMainSize;
        int _gameStrategy;
        bool _pause;
        Vector2 _velocity;
        Vector2 _stageSize;
        spBot _player;
        std::vector <spBot> _bots;
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
};

DECLARE_SMART(Game, spGame)

