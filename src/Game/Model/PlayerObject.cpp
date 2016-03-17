#include "PlayerObject.h"

PlayerObject::PlayerObject(Vector2 position, int size):
    GameObject(position)
{
    if(size <= 0 || size > 100)
        _size = rand() % 85 + 4; //TODO
    else
        _size = size;

    _velocity = Vector2(0,0);
}

PlayerObject::~PlayerObject()
{}

void PlayerObject::reInitialize(Vector2 position, int maxSize)
{
    setPosition(position);
    _size = rand() % (maxSize + 1) + 5;
    _velocity = Vector2(0,0);
}

void PlayerObject::eat(spPlayerObject other)
{
    double cSize = other->getSize();
    _size += cSize / _size;
}

Vector2 PlayerObject::getVelocity()
{
    return _velocity;
}

double PlayerObject::getSize()
{
    return _size;
}

void PlayerObject::accelerate(const Vector2& acceleration, double time)
{
    _velocity += acceleration / 2;
    setPosition( getPosition() + _velocity );
    _velocity.x -=  _velocity.x * _size / 250;
    _velocity.y -= _velocity.y * _size / 250;
}

void PlayerObject::move(const Vector2& deltaPosition)
{
    setPosition( getPosition() + deltaPosition );
}

