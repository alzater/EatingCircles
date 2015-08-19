#pragma once
#include "oxygine-framework.h"
#include <functional>
using namespace oxygine;

class Star;

typedef oxygine::intrusive_ptr <Star> spStar;

class Star : public Sprite
{
  public:
    Star(Vector2 vect);
    ~Star();
    void move(Vector2 deltaPosition);
    bool isInRectangle(Vector2 start, Vector2 end);
  private:
    void initializeBig();
    void initializeLittle();
    void initializePulsar();
    double  size_;
};

