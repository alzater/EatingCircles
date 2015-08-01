#include "menu.h"

static Resources gameResources;

Menu::Menu()
{
    if( !gameResources.getUseLoadCounter() )
        gameResources.loadXML("res.xml");
	style.font = gameResources.getResFont("invaders")->getFont();
	style.color = Color::White;
	style.vAlign = TextStyle::VALIGN_MIDDLE;
	style.hAlign = TextStyle::HALIGN_CENTER;
    setPosition(getStage()->getSize().x / 2, 200);
}

void Menu::addItem(std::string text)
{
	spTextField item = new TextField();
	int position = 0;
	if(!items.empty())
	{
		position = items.back()->getY();
		position += style.font->getSize() / style.font->getScale() * 2;
	}
	addChild(item);
	item->setPosition(0, position);
	item->setText(text);
	item->setStyle(style);
	items.push_back(item);
}

void Menu::addItem(std::string text, EventCallback onClick)
{
    spButton b = new Button();
    int position = 0;
	addChild(b);
	b->setPosition(0, position);
    spTextField item = new TextField();
	item->setText(text);
    item->attachTo(b);
    b->setResAnim(gameResources.getResAnim("button"));
	b->addEventListener(TouchEvent::CLICK, onClick);
}

void Menu::setFont(Font* f){
    style.font = f;
}

void Menu::setTextColor(Color c){
    style.color = c;
}

void Menu::setHAlign(TextStyle::HorizontalAlign ha){
    style.hAlign = ha;
}

void Menu::setVAlign(TextStyle::VerticalAlign va){
    style.vAlign = va;
}

