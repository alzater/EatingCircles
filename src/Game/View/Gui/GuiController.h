#include "GuiObject.h"

class GuiController
{
    public:
        static spGuiObject getGuiObject(int type);
    private:
        Color getColor();
};


