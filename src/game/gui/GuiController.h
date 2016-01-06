#include "GuiObject.h"

class GuiController
{
    public:
        static spGuiObject getGuiObject(const Vector2& position, const double size,
                const Color& color, const int type);
    private:
        Color getColor();
};


