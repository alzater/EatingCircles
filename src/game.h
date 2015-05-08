#pragma once
#include "oxygine-framework.h"
#include <functional>
#include "circle.h"
#include "Polygon.h"
#include <vector>

using namespace oxygine;

class Game{
public:
    Game(int l);
    bool nextFrame();
    int getScore();
private:
    int level, score, num_of_bots;
    Vector2 stage_size;
    spCircle main_circle;
    std::vector <spCircle> circles;
    
    Vector2 getRandomCoords();
    void main_circle_turn();
    void make_turn();
    bool check_main_circle();
    void check_bots_positions();
    void renew_circle(spCircle& circle);
    void check_eaters();
    
    spPolygon poly;
};
