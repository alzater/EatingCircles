#ifndef __BOT_H__
#define __BOT_H__

#include "GameObject.h"

using namespace oxygine;

DECLARE_SMART(Bot, spBot)

class Bot : public GameObject, public Object
{
    public:
        Bot(Vector2 position, int size, int type = 0);
        void reInitialize(Vector2 position, int maxSize, int type = 0);
        virtual ~Bot();

        virtual void move(const Vector2& deltaPosition);
        virtual void eat(spBot other);
        virtual void accelerate(const Vector2& acceleration, double time);

        double getSize();
        void setSize(double size);
        Vector2 getVelocity();
        void setVelocity(Vector2 velocity);

        int getPower();
        int getMana();
        int getAgility();

        void updateAbilities();
        void boost(); // from blue-mana
        double getBonusSpeed();
        double getBoosterSize();

    private:
        double _size;
        Vector2 _velocity;

        double _lostSize, _booster;
        int _power, _mana, _agility;
        //TODO const int MAX_BOOSTER_SIZE = 1000;

        void loseMass(); // from red-power
        void updateBooster();
};

#endif
