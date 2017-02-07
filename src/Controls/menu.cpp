#include "menu.h"

static Resources gameResources;

Menu::Menu(const Vector2& position)
{
    if( !gameResources.getUseLoadCounter() )
        gameResources.loadXML("res.xml");
    menu = new Actor();
    menu->setPosition(position);
    setDefaultStyle(labelStyle);
    setDefaultStyle(buttonStyle);
    buttonStyle.fontSize = 20;
    lastHPos = 0;

    background = new ColorRectSprite;
    background->setColor(Color(50, 15, 15));
    background->setAnchor(Vector2(0.5, 0.5));
    background->setPosition(0, 100);
    background->attachTo(menu);
}

void Menu::addItem(std::string text)
{
    spTextField label = new TextField();
    menu->addChild(label);
    label->setPosition(0, lastHPos);
    label->setText(text);
    label->setStyle(labelStyle);
    lastHPos += 40;
    background->setSize(300, lastHPos + 100);

}

void Menu::addItem(std::string text, EventCallback onClick)
{
    spButton b = new Button();
    b->setName(std::string("Button") + text);
    menu->addChild(b);
    b->setResAnim(gameResources.getResAnim("button"));
    b->setPosition(Vector2(-95, lastHPos -15));
    spTextField item = new TextField();
    item->setText(text);
    item->setSize(b->getSize());
    item->setStyle(buttonStyle);
    b->addChild(item);
    b->addEventListener(TouchEvent::CLICK, onClick);
    lastHPos += 60;
    background->setSize(300, lastHPos + 100);
}

void Menu::addToActor(spActor actor)
{
    actor->addChild(menu);
}

void Menu::setDefaultStyle(TextStyle& style){
    style.font = gameResources.getResFont("invaders");
    style.color = Color::White;
    style.vAlign = TextStyle::VALIGN_MIDDLE;
    style.hAlign = TextStyle::HALIGN_MIDDLE;
    style.fontSize = 30;
}

void Menu::setFont(ResFont* f, int sw){  // 0 - both, 1 - label, 2 - button
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

void Menu::setTextScale(int sc, int sw){  // 0 - both, 1 - label, 2 - button
    switch(sw){
    case 0:
        labelStyle.fontSize = sc;
        buttonStyle.fontSize = sc;
        break;
    case 1:
        labelStyle.fontSize = sc;
        break;
    case 2:
        buttonStyle.fontSize = sc;
    }
}



