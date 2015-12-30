#include "oxygine-framework.h"
#include <functional>

#include <iostream>

#include "circle.h"

using namespace oxygine;


static Resources gameResources;

Circle::Circle(Vector2 position, int size, Color color)
{
    if(size <= 0 || size > 100)
        _size = rand() % 85 + 4;
    else
        _size = size;

    setPosition(position);

    setColor( color );

    if( !gameResources.getUseLoadCounter() )
    {
        gameResources.loadXML("res.xml");
    }
    setInputEnabled(false);
    setUserData(0);
    setAnimFrame(gameResources.getResAnim("circle"));
    setScale(_size / 60);
    _lostSize = 0;
    velocity = Vector2(0,0);
    setAnchor( 0.5, 0.5);
    Actor::setSize(Vector2(60,60));
}

void Circle::reInitialize(Vector2 position, int maxSize, Color color)
{
    setPosition(position);
    _size = rand() % (maxSize + 1) + 5;
    setColor( color );
    setScale(_size / 60);
    _lostSize = 0;
    velocity = Vector2(0,0);
}

Circle::~Circle()
{
}

void Circle::accelerate(Vector2 acceleration, double time)
{
    velocity += acceleration / 2;
    setPosition( getPosition() + velocity );
    velocity.x -=  velocity.x * _size / 250;
    velocity.y -= velocity.y * _size / 250;
}

void Circle::move(Vector2 deltaPosition)
{
    setPosition( getPosition() + deltaPosition );
}

void Circle::updateGui()
{
    setScale(_size / 60);
}

double Circle::getSize()
{
    return _size;
}

Vector2 Circle::getVelocity()
{
    return velocity;
}

void Circle::eatCircle(spCircle& circle)
{
    Color color = getColor();
    double cSize = circle->getSize();
    Color cColor = circle->getColor();

    color.r = (color.r * _size + cColor.r * cSize) / (_size + cSize);
    color.g = (color.g * _size + cColor.g * cSize) / (_size + cSize);
    color.b = (color.b * _size + cColor.b * cSize) / (_size + cSize);
    _size += cSize / _size;

    setColor(color);
    updateGui();
}

bool Circle::isInRectangle(Vector2 start, Vector2 end)
{
    Vector2 currentPosition = getPosition();
    if( currentPosition.x < start.x || currentPosition.x > end.x ||
            currentPosition.y < start.y || currentPosition.y > end.y){
        return false;
    }
    else {
        return true;
    }
}

void Circle::updateAbilities()
{
    loseMass();
    updateBooster();
}

void Circle::loseMass()
{
    double changeSize = _size * ((double)( 200 - getPower() )) / 2000000.0;
    _lostSize += changeSize;
    _size -= changeSize;

    if(_lostSize > 0.5){
        _lostSize = 0;
        updateGui();
    }
}

void Circle::updateBooster()
{
    _booster += 0.02 * (double) getMana();
    if(_booster >= MAX_BOOSTER_SIZE + getMana())
        _booster = MAX_BOOSTER_SIZE + getMana();
}

double Circle::getBonusSpeed()
{
    return (double) getAgility() / 255.0;
}

double Circle::getBoosterSize()
{
    return _booster;
}

void Circle::boost()
{
    velocity *= 1.0 + getBoosterSize();
    _booster -= 50;
    if( _booster < 0 )
        _booster = 0;
}

void Circle::makeRandomTurn()
{
    accelerate(Vector2( rand() % 3 - 1 , rand() % 3 - 1 ), 1.0 / 100);
    updateAbilities();
}

void Circle::makeLinerTurn(float deviation)
{
    if(velocity.x == 0 && velocity.y == 0)
    {
        makeRandomTurn();
        return;
    }

    if(deviation < 0 || deviation > 1)
        deviation = 0;

    Vector2 result;
    float znam = std::sqrt( velocity.x * velocity.x + velocity.y * velocity.y );
    if(znam > 0)
        result = velocity / znam ;
    else
        result = velocity;

    result.x += (rand() % 3 - 1) * deviation;
    if (result.x > 1)
        result.x = 1;
    if (result.x < -1)
        result.x = -1;

    result.y += (rand() % 3 - 1) * deviation;
    if (result.y > 1)
        result.y = 1;
    if (result.y < -1)
        result.y = -1;

    accelerate(result, 1.0 / 100);
    updateAbilities();
}

void Circle::makeIntellectualTurn(const std::vector <spCircle>& circles, float stupidity){
    if (stupidity < 0 || stupidity > 1)
        stupidity = 0;

    Vector2 result(0, 0);
    for(int i = 0; i < circles.size(); ++i)
    {
        if (circles[i].get() == this)
            continue;

        Vector2 cPosition = circles[i]->getPosition();
        double xDistance = cPosition.x - getPosition().x;
        double yDistance = cPosition.y - getPosition().y;

        if ( _size < circles[i]->getSize() ){
            xDistance *= -1.0;
            yDistance *= -1.0;
        }

        if ( xDistance != 0 )
            result.x += 1000.0 / xDistance * 1000.0 / xDistance * 1000.0 / xDistance;
        if ( yDistance != 0 )
            result.y += 1000.0 / yDistance * 1000.0 / yDistance * 1000.0 / yDistance;
    }

    result.x += (rand() % 3 - 1) * stupidity;
    if (result.x > 1)
        result.x = 1;
    if (result.x < -1)
        result.x = -1;

    result.y += (rand() % 3 - 1) * stupidity;
    if (result.y > 1)
        result.y = 1;
    if (result.y < -1)
        result.y = -1;

    double distance = std::sqrt( result.x * result.x + result.y * result.y );
    if ( distance > 0.0005 ){
        result.x /= distance;
        result.y /= distance;
    }

    accelerate(result, 1.0 / 100);  
    updateAbilities();
}

int Circle::getPower()
{
    return getColor().r;
}

int Circle::getMana()
{
    return getColor().b;
}

int Circle::getAgility()
{
    return getColor().g;
}

