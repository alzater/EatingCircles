#ifndef __BOT_H__
#define __BOT_H__

#include "PlayerObject.h"

using namespace oxygine;

class Bot : public PlayerObject
{
    public:
        Bot(Vector2 position, int s, int type = 0);
        void reInitialize(Vector2 position, int maxSize, int type = 0);
        virtual ~Bot();

        virtual void move(const Vector2& deltaPosition);
        virtual void eat(spPlayerObject other);
        virtual void accelerate(const Vector2& ys, double time);

        void addGuiToScene(spActor actor);

        void updateAbilities();
        void boost(); // from blue-mana
        double getBonusSpeed();
        double getBoosterSize();

    private:
        void updateGui();
        int getPower();
        int getMana();
        int getAgility();
        void loseMass(); // from red-power
        void updateBooster();
        Color getColor();
        void setColor(const Color& color);
        Color generateColor();

        //TODO const int MAX_BOOSTER_SIZE = 1000;
        double _lostSize, _booster;
        Color _color;
        spGuiObject gui;
};

typedef oxygine::intrusive_ptr <Bot> spBot;

#endif
