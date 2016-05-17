#ifndef __GAME_H__
#define __GAME_H__

#include "oxygine-framework.h"
#include <functional>
#include "Unit.h"
#include "Polygon.h"
#include "../View/ExtraObjects/star.h"
#include "UnitController/AI.h"
#include <vector>

using namespace oxygine;

class GameResults
{
public:
    GameResults() : _score(0), _nEated(0) {}

    void setScore(int score){_score = score;}
    int getScore(){return _score;}

    void setNEated(int nEated){_nEated = nEated;}
    void incNEated(){_nEated++;}
    int getNEated(){return _nEated;}

private:
    int _score, _nEated;
};

class Game : public Object
{
    public:
        Game(int gameStrategy = 0);
        void initialize();

        int update();

        void moveAll(const Vector2& vector);

        const GameResults& getResult() const;

        void pause();
        void resume();
    private:
        int _level, _nUnits, _nStars, _maxMainSize;
        int _gameStrategy;
        bool _pause;
        Vector2 _velocity;
        Vector2 _stageSize;
        spUnit _player;
        std::vector <spUnit> _units;
        std::vector <spStar> _stars;
        GameResults _results;

        //private function
        const Vector2& getRandomCoords() const;
        void mainCircleTurn();
        void makeTurn();
        bool checkMainCircle();
        void checkUnitsPositions();
        void checkEaters();
};

DECLARE_SMART(Game, spGame)

#endif
