#include "menu.h"

static Resources gameResources;

Menu::Menu()
{
    if( !gameResources.getUseLoadCounter() )
        gameResources.loadXML("res.xml");
    setPosition(getStage()->getSize().x / 2, 200);
    setDefaultStyle(labelStyle);
    buttonStyle.font = labelStyle.font;
    //buttonStyle.hAlign = labelStyle.hAlign;
    lastHPos = 0;
}

void Menu::addItem(std::string text)
{
	spTextField label = new TextField();
	addChild(label);
	label->setPosition(0, lastHPos);
	label->setText(text);
	label->setStyle(labelStyle);
    lastHPos += 50;

}

void Menu::addItem(std::string text, EventCallback onClick)
{
    spButton b = new Button();
    b->setResAnim(gameResources.getResAnim("button"));
	addChild(b);
	b->setPosition(Vector2(-95, lastHPos));
    spTextField item = new TextField();
	item->setText(text);
    item->setSize(b->getSize());
    item->setStyle(labelStyle);
    b->addChild(item);
	b->addEventListener(TouchEvent::CLICK, onClick);
    lastHPos += 70;
}

void Menu::setDefaultStyle(TextStyle& style){
    style.font = gameResources.getResFont("invaders")->getFont();
    style.color = Color::White;
    style.vAlign = TextStyle::VALIGN_MIDDLE;
    style.hAlign = TextStyle::HALIGN_CENTER;
    style.fontSize2Scale = 20;
}

void Menu::setFont(Font* f, int sw){  // 0 - both, 1 - label, 2 - button
    switch(sw){
    case 0:
        labelStyle.font = f;
        buttonStyle.font = f;
        break;
    case 1:
        labelStyle.font = f;
        break;
    case 2:
        buttonStyle.font = f;
    }
}

void Menu::setTextColor(Color c, int sw){  // 0 - both, 1 - label, 2 - button
    switch(sw){
    case 0:
        labelStyle.color = c;
        buttonStyle.color = c;
        break;
    case 1:
        labelStyle.color = c;
        break;
    case 2:
        buttonStyle.color = c;
    }
}
void Menu::setHAlign(TextStyle::HorizontalAlign ha, int sw){  // 0 - both, 1 - label, 2 - button
    switch(sw){
    case 0:
        labelStyle.hAlign = ha;
        buttonStyle.hAlign = ha;
        break;
    case 1:
        labelStyle.hAlign = ha;
        break;
    case 2:
        buttonStyle.hAlign = ha;
    }
}
void Menu::setVAlign(TextStyle::VerticalAlign va, int sw){  // 0 - both, 1 - label, 2 - button
    switch(sw){
    case 0:
        labelStyle.vAlign = va;
        buttonStyle.vAlign = va;
        break;
    case 1:
        labelStyle.vAlign = va;
        break;
    case 2:
        buttonStyle.vAlign = va;
    }
}



