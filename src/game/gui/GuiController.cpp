#include "GuiController.h"
#include "Circle.h"
#include "Packman.h"

spGuiObject GuiController::getGuiObject(const Vector2& position, const double size,
        const Color& color, int type)
{
    int chose = rand() % 2;
    spGuiObject gui;
    if (chose)
        gui = new Circle(position, size, color);
    else
        gui = new Packman(position, size, color);
    return gui;
}
