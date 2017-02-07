#pragma once
#include "oxygine-framework.h"
#include <list>

using namespace oxygine;

class Menu : public Object
{
public:
    Menu(const Vector2& position);
    void addItem(std::string text, EventCallback onClick);
    void addItem(std::string text);
    void addToActor(spActor actor);

    void setFont(ResFont* f, int sw = 0);// 0 - both, 1 - label, 2 - button
    void setTextColor(Color c, int sw = 0);// 0 - both, 1 - label, 2 - button
    void setHAlign(TextStyle::HorizontalAlign ha, int sw = 0);// 0 - both, 1 - label, 2 - button
    void setVAlign(TextStyle::VerticalAlign va, int sw = 0);// 0 - both, 1 - label, 2 - button
    void setTextScale(int sc, int sw);// 0 - both, 1 - label, 2 - button
private:
    int lastHPos;
    TextStyle labelStyle, buttonStyle;
    void setDefaultStyle(TextStyle& style);
    spActor menu;
    spColorRectSprite background;
};

typedef oxygine::intrusive_ptr<Menu> spMenu;
