#pragma once
#include "oxygine-framework.h"
#include <functional>
#include "circle.h"
#include "Polygon.h"
#include "star.h"
#include <vector>

using namespace oxygine;

class Game: public Actor{
public:
    Game(int l);
    bool nextFrame();
    int getScore();
private:
    int level, score, num_of_bots, eated, num_of_stars;
    Vector2 velocity;
    Vector2 stage_size;
    spCircle main_circle;
    std::vector <spCircle> circles;
    std::vector <spStar> stars;
    
    Vector2 getRandomCoords();
    void main_circle_turn();
    void make_turn();
    bool check_main_circle();
    void check_bots_positions();
    void renew_circle(spCircle& circle);
    void check_eaters();
    spPolygon poly;
};
