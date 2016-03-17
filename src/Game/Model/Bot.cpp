#include "Bot.h"

Bot::Bot(Vector2 position, int size, int type):
    PlayerObject(position, size),
    _color(generateColor())
{
    _lostSize = 0;
    //gui = GuiController::getGuiObject(position, size, _color, type);
    gui->update(position, size, _color);
}

Bot::~Bot()
{}

void Bot::reInitialize(Vector2 position, int maxSize, int type)
{
    _lostSize = 0;
    PlayerObject::reInitialize(position, maxSize);
}

void Bot::updateGui()
{
    gui->update(_position, _size, _color);
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
        updateGui();
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
    return getColor().r;
}

int Bot::getMana()
{
    return getColor().b;
}

int Bot::getAgility()
{
    return getColor().g;
}

Color Bot::getColor()
{
    return _color;
}

void Bot::setColor(const Color& color)
{
    _color = color;
}
void Bot::move(const Vector2& deltaPosition)
{
    PlayerObject::move(deltaPosition);
    updateGui();
}

void Bot::eat(spPlayerObject other)
{
    PlayerObject::eat(other);
    updateGui();
}

void Bot::accelerate(const Vector2& ys, double time)
{
    PlayerObject::accelerate(ys, time);
    updateGui();
}

void Bot::addGuiToScene(spActor actor)
{
    gui->attachTo(actor);
}

Color Bot::generateColor()
{
    return Color(rand() % 155 + 100, rand() % 155 + 100, rand() % 155 + 100);
}
