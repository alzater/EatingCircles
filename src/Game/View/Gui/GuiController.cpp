#include "GuiController.h"
#include "Circle.h"
#include "Packman.h"

spGuiObject GuiController::getGuiObject(const Vector2& position, const double size,
        const Color& color, int type)
{
    int chose = rand() % 2;
    spGuiObject gui;
    switch(type)
    {
    case 0:
        gui = new Circle(position, size, color);
        break;
    case 1:
        gui = new Packman(position, size, color);
        break;
    default:
        gui = new Circle(position, size, color);
        break;
    }

    return gui;
}
