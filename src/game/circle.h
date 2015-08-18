#pragma once
#include "oxygine-framework.h"
#include <functional>
using namespace oxygine;

class Circle;

typedef oxygine::intrusive_ptr <Circle> spCircle;

class Circle : public Sprite{
  public:
    Circle(int s, int x, int y, Color color);
    Circle(Vector2 vect);
    void reInitialize(Vector2 vect);
    void randomInitialize();
    void allInitialize();
    ~Circle();
    void loseMass(); // from red-power
    void accelerate(Vector2 ys, double time);
    void move(Vector2 deltaPosition);
    double getSize();
    void eatCircle(spCircle& circle);
    Vector2 getCenter();
    Vector2 getVelocity();
    bool isInRectangle(Vector2 start, Vector2 end);
    
    void makeRandomTurn();
    void makeLinerTurn(float deviation = 0);
    void makeIntellectualTurn(const std::vector <spCircle>& circle, float stupidity = 0);
    
  private:
    void updateGui();
    void boost(); // from blue-mana
    int getPower();
    int getMana();
    int getAgility();
    double  size_, lostSize_;
    Vector2 velocity;
};

