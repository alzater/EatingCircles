#include "oxygine-framework.h"

#include <vector>

#include "Gui/GuiObject.h"

using oxygine::Actor;
using oxygine::ColorRectSprite;
using std::vector;

class GameView: public Actor
{
public:
    GameView();
    ~GameView();

    void addGuiObject();
private:
    oxygine::spColorRectSprite _background;
    vector<spGuiObject> _objects;
};
