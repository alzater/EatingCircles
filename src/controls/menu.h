#include "oxygine-framework.h"
#include <list>

using namespace oxygine;

class Menu : public Actor
{
private:
    int lastHPos;
    TextStyle labelStyle, buttonStyle;
    void setDefaultStyle(TextStyle& style);
public:
    Menu();
    void addItem(std::string text, EventCallback onClick);
    void addItem(std::string text);

    void setFont(Font* f, int sw = 0);// 0 - both, 1 - label, 2 - button
    void setTextColor(Color c, int sw = 0);// 0 - both, 1 - label, 2 - button
    void setHAlign(TextStyle::HorizontalAlign ha, int sw = 0);// 0 - both, 1 - label, 2 - button
    void setVAlign(TextStyle::VerticalAlign va, int sw = 0);// 0 - both, 1 - label, 2 - button
};

typedef oxygine::intrusive_ptr<Menu> spMenu;
    
