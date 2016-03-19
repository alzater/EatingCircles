#ifndef __GAME_H__
#define __GAME_H__

#include "oxygine-framework.h"
#include <functional>
#include "Unit.h"
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
        int _level, _score, _nUnits, _nEated, _nStars, _maxMainSize;
        int _gameStrategy;
        bool _pause;
        Vector2 _velocity;
        Vector2 _stageSize;
        spUnit _player;
        std::vector <spUnit> _units;
        std::vector <spStar> _stars;
        timeMS _lastTime;
        double _timeMultiplier;

        Vector2 getRandomCoords();
        void mainCircleTurn();
        void makeTurn();
        bool checkMainCircle();
        void checkUnitsPositions();
        void checkEaters();
        Color genCircleColor();
        Color genStarColor();
        bool updateFrameTimeMultiplier();
};

DECLARE_SMART(Game, spGame)

#endif
