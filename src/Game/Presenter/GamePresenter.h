#include "oxygine-framework.h"

#include "../Model/Game.h"

using oxygine::EventDispatcher;

class GamePresenter : public EventDispatcher
{
public:
    GamePresenter(int level);
private:
    spGame _game;
};
