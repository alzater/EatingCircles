#include "oxygine-framework.h"
#include "GuiObject.h"

using namespace oxygine;

class Circle : public GuiObject
{
  public:
    Circle(const Vector2& position, const double size = 0, const Color& color = Color(255, 255, 255));
    virtual ~Circle();

    virtual void update(const Vector2& position, const double size, const Color& color);
  private:
    spSprite circle;
};

