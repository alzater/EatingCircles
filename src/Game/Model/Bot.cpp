#include "Bot.h"

Bot::Bot(Vector2 position, int size, int type):
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

Bot::~Bot()
{}

void Bot::reInitialize(Vector2 position, int maxSize, int type)
{
    _lostSize = 0;
    setPosition(position);
    _size = rand() % (maxSize + 1) + 5;
    _velocity = Vector2(0,0);
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
    setPosition( getPosition() + deltaPosition );
}

void Bot::eat(spBot other)
{
    double cSize = other->getSize();
    _size += cSize / _size;
}

Vector2 Bot::getVelocity()
{
    return _velocity;
}

double Bot::getSize()
{
    return _size;
}


void Bot::accelerate(const Vector2& acceleration, double time)
{
    _velocity += acceleration / 2;
    setPosition( getPosition() + _velocity );
    _velocity.x -=  _velocity.x * _size / 250;
    _velocity.y -= _velocity.y * _size / 250;
}
