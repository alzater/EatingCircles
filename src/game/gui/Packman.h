#include "oxygine-framework.h"
#include "GuiObject.h"

using namespace oxygine;

class Packman : public GuiObject
{
  public:
    Packman(const Vector2& position, const double size = 0, const Color& color = Color(255, 255, 255));
    virtual ~Packman();

    virtual void update(const Vector2& position, const double size, const Color& color);
  private:
    spSprite _packman;
};

