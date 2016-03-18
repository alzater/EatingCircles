#include "GameObject.h"

GameObject::GameObject(const Vector2& position):
    _position(position)
{}

GameObject::~GameObject()
{}

bool GameObject::isInRectangle(const Vector2& start, const Vector2& end)
{
    if( _position.x < start.x || _position.x > end.x || _position.y < start.y || _position.y > end.y)
        return false;
    else
        return true;
}

void GameObject::setPosition(const Vector2& position)
{
    _position = position;
}

const Vector2& GameObject::getPosition()
{
    return _position;
}
