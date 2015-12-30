#pragma once

#include "oxygine-framework.h"
#include <functional>

using namespace oxygine;

class Circle;

typedef oxygine::intrusive_ptr <Circle> spCircle;

class Circle : public Sprite
{
    public:
        Circle( Vector2 position, int s, Color color);
        void reInitialize(Vector2 position, int maxSize, Color color);
        ~Circle();

        void updateAbilities();
        void boost(); // from blue-mana
        double getBonusSpeed();
        double getBoosterSize();
        void accelerate(Vector2 ys, double time);
        void move(Vector2 deltaPosition);
        double getSize();
        void eatCircle(spCircle& circle);
        Vector2 getVelocity();
        bool isInRectangle(Vector2 start, Vector2 end);

        void makeRandomTurn();
        void makeLinerTurn(float deviation = 0);
        void makeIntellectualTurn(const std::vector <spCircle>& circle, float stupidity = 0);

    private:
        void updateGui();
        int getPower();
        int getMana();
        int getAgility();
        void loseMass(); // from red-power
        void updateBooster();

        const int MAX_BOOSTER_SIZE = 1000;
        double _size, _lostSize, _booster;
        Vector2 velocity;
};

