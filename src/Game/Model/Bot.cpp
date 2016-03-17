#include "Bot.h"

Bot::Bot(Vector2 position, int size, int type):
    PlayerObject(position, size),
    _lostSize(0),
    _mana(200),
    _agility(200),
    _power(200)
{}

Bot::~Bot()
{}

void Bot::reInitialize(Vector2 position, int maxSize, int type)
{
    _lostSize = 0;
    PlayerObject::reInitialize(position, maxSize);
}

void Bot::updateAbilities()
{
    loseMass();
    updateBooster();
}

void Bot::loseMass()
{
    double changeSize = _size * ((double)( 200 - getPower() )) / 2000000.0;
    _lostSize += changeSize;
    _size -= changeSize;

    if(_lostSize > 0.5){
        _lostSize = 0;
    }
}

void Bot::updateBooster()
{
    _booster += 0.02 * (double) getMana();
    if(_booster >= 1000 + getMana()) //TODO MAX_BOOSTER_SIZE
        _booster = 1000 + getMana();
}

double Bot::getBonusSpeed()
{
    return (double) getAgility() / 255.0;
}

double Bot::getBoosterSize()
{
    return _booster;
}

void Bot::boost()
{
    _velocity *= 1.0 + getBoosterSize();
    _booster -= 50;
    if( _booster < 0 )
        _booster = 0;
}


int Bot::getPower()
{
    return _power;
}

int Bot::getMana()
{
    return _mana;
}

int Bot::getAgility()
{
    return _agility;
}

void Bot::move(const Vector2& deltaPosition)
{
    PlayerObject::move(deltaPosition);
}

void Bot::eat(spPlayerObject other)
{
    PlayerObject::eat(other);
}

void Bot::accelerate(const Vector2& ys, double time)
{
    PlayerObject::accelerate(ys, time);
}
