#include "AI.h"

void AI::makeRandomTurn(spBot player)
{
    player->accelerate(Vector2( rand() % 3 - 1 , rand() % 3 - 1 ), 1.0 / 100);
}

void AI::makeLinerTurn(spBot player, float deviation)
{
    Vector2 velocity = player->getVelocity();
    if(velocity.x == 0 && velocity.y == 0)
    {
        makeRandomTurn(player);
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

    player->accelerate(result, 1.0 / 100);
}

void AI::makeIntellectualTurn(spBot player, const std::vector <spBot>& others, float stupidity)
{
    if (stupidity < 0 || stupidity > 1)
        stupidity = 0;

    Vector2 result(0, 0);
    for(int i = 0; i < others.size(); ++i)
    {
        if (others[i] == player)
            continue;

        Vector2 cPosition = others[i]->getPosition();
        Vector2 position = player->getPosition();
        double size = player->getSize();

        double xDistance = cPosition.x - position.x;
        double yDistance = cPosition.y - position.y;

        if ( size < others[i]->getSize() ){
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

    player->accelerate(result, 1.0 / 100);
}
