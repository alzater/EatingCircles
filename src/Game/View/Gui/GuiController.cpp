#include "GuiController.h"
#include "Circle.h"
#include "Packman.h"

spGuiObject GuiController::getGuiObject(int type)
{
    int chose = rand() % 2;
    spGuiObject gui;
    switch(type)
    {
    case 0:
        gui = new Circle;
        break;
    case 1:
        gui = new Packman;
        break;
    default:
        gui = new Circle;
        break;
    }

    return gui;
}
