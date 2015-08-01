#include "oxygine-framework.h"
#include <list>

using namespace oxygine;

class Menu : public Actor
{
private:
	std::list<spTextField> items;
    TextStyle style;
public:

	Menu();
	void addItem(std::string text, EventCallback onClick);
	void addItem(std::string text);
    
    void setFont(Font* f);
    void setTextColor(Color c);
    void setHAlign(TextStyle::HorizontalAlign ha);
    void setVAlign(TextStyle::VerticalAlign va);
};

typedef oxygine::intrusive_ptr<Menu> spMenu;
    
