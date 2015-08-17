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
    Game(int l, int gs = 0);
    int nextFrame();
    const GameResults getResult();
    int getMainCircleSize();
    double getFrameTimeMultiplier();
private:
    int level, score, num_of_bots, eated, num_of_stars, max_main_size;
    int game_strategy;
    Vector2 velocity;
    Vector2 stage_size;
    spCircle main_circle;
    std::vector <spCircle> circles;
    std::vector <spStar> stars;
    timeMS lastTime;
    double timeMultiplier;
    
    Vector2 getRandomCoords();
    void main_circle_turn();
    void make_turn();
    bool check_main_circle();
    void check_bots_positions();
    void check_eaters();
    Color genCircleColor();
    Color genStarColor();
    bool updateFrameTimeMultiplier();
    
    //---game strategy----
    void game_beginer();
    void game_easy();
    void game_medium();
    void game_hard();
    void game_ultra_hard();    
};

typedef oxygine::intrusive_ptr<Game> spGame;
