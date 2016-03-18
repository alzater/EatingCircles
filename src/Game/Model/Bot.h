#ifndef __BOT_H__
#define __BOT_H__

#include "GameObject.h"

using namespace oxygine;

DECLARE_SMART(Bot, spBot)
class BotEvent: public Event
{
public:
    enum
    {
        EATED = eventID('B', 'E', 'E', 't'),
        MOVED = eventID('B', 'E', 'M', 'o'),
        NEW_SIZE  = eventID('B', 'E', 'N', 'S'),
    };

    BotEvent(int type): Event(type) {}
};

class Bot : public GameObject
{
    public:
        Bot(const Vector2& position, int size, int type = 0);
        void reInitialize(const Vector2& position, int maxSize, int type = 0);
        virtual ~Bot();

        virtual void move(const Vector2& deltaPosition);

        void eat(spBot other);
        void accelerate(const Vector2& acceleration, double time);

        double getSize();
        void setSize(double size);
        const Vector2& getVelocity();
        void setVelocity(const Vector2& velocity);

        int getPower();
        int getMana();
        int getAgility();

        void updateAbilities();
        void boost(); // from blue-mana
        double getBonusSpeed();
        double getBoosterSize();

        void dispatchEated();
        void dispatchMoved();
        void dispatchNewSize();

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
