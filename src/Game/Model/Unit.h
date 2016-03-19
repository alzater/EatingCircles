#ifndef __UNIT_H__
#define __UNIT_H__

#include "GameObject.h"

using namespace oxygine;

DECLARE_SMART(Unit, spUnit)
class UnitEvent: public Event
{
public:
    enum
    {
        EATED = eventID('U', 'E', 'E', 't'),
        MOVED = eventID('U', 'E', 'M', 'o'),
        NEW_SIZE  = eventID('U', 'E', 'N', 'S'),
    };

    UnitEvent(int type): Event(type) {}
};

class Unit : public GameObject
{
    public:
        Unit(const Vector2& position, int size, int type = 0);
        void reInitialize(const Vector2& position, int maxSize, int type = 0);
        virtual ~Unit();

        virtual void move(const Vector2& deltaPosition);

        void eat(spUnit other);
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
