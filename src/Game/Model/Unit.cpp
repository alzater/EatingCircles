#include "Unit.h"

Unit::Unit(const Vector2& position, int size, int type):
    GameObject(position),
    _lostSize(0),
    _mana(200),
    _agility(200),
    _power(200)
{
    if(size <= 0 || size > 100)
        _size = rand() % 85 + 4; //TODO
    else
        _size = size;

    _velocity = Vector2(0,0);
}

Unit::~Unit()
{
    dispatchEated();
}

void Unit::reInitialize(const Vector2& position, int maxSize, int type)
{
    _lostSize = 0;
    setPosition(position);
    _size = rand() % (maxSize + 1) + 5;
    _velocity = Vector2(0,0);
    dispatchMoved();
}

void Unit::updateAbilities()
{
    loseMass();
    updateBooster();
}

void Unit::loseMass()
{
    double changeSize = _size * ((double)( 200 - getPower() )) / 2000000.0;
    _lostSize += changeSize;
    _size -= changeSize;

    if(_lostSize > 0.5){
        _lostSize = 0;
        dispatchNewSize();
    }
}

void Unit::updateBooster()
{
    _booster += 0.02 * (double) getMana();
    if(_booster >= 1000 + getMana()) //TODO MAX_BOOSTER_SIZE
        _booster = 1000 + getMana();
}

double Unit::getBonusSpeed()
{
    return (double) getAgility() / 255.0;
}

double Unit::getBoosterSize()
{
    return _booster;
}

void Unit::boost()
{
    _velocity *= 1.0 + getBoosterSize();
    _booster -= 50;
    if( _booster < 0 )
        _booster = 0;
}


int Unit::getPower()
{
    return _power;
}

int Unit::getMana()
{
    return _mana;
}

int Unit::getAgility()
{
    return _agility;
}

void Unit::move(const Vector2& deltaPosition)
{
    setPosition( getPosition() + deltaPosition );
    dispatchMoved();
}

void Unit::eat(spUnit other)
{
    double cSize = other->getSize();
    _size += cSize / _size;
    dispatchNewSize();
}

const Vector2& Unit::getVelocity()
{
    return _velocity;
}

double Unit::getSize()
{
    return _size;
}


void Unit::accelerate(const Vector2& acceleration, double time)
{
    _velocity += acceleration / 2;
    setPosition( getPosition() + _velocity );
    _velocity.x -=  _velocity.x * _size / 250;
    _velocity.y -= _velocity.y * _size / 250;
    dispatchMoved();
}

void Unit::dispatchEated()
{
    UnitEvent ue(UnitEvent::EATED);
    dispatchEvent(&ue);
}

void Unit::dispatchMoved()
{
    UnitEvent ue(UnitEvent::MOVED);
    dispatchEvent(&ue);
}

void Unit::dispatchNewSize()
{
    UnitEvent ue(UnitEvent::NEW_SIZE);
    dispatchEvent(&ue);
}