#ifndef __PLAYER_OBJECT_H__
#define __PLAYER_OBJECT_H__

#include "oxygine-framework.h"

#include "GameObject.h"
#include "../View/Gui/GuiController.h"


using namespace oxygine;


class PlayerObject;

typedef oxygine::intrusive_ptr <PlayerObject> spPlayerObject;

class PlayerObject : public GameObject, public Object
{
    public:
        PlayerObject(Vector2 position, int size);
        void reInitialize(Vector2 position, int maxSize);
        virtual ~PlayerObject();

        virtual void move(const Vector2& deltaPosition);
        virtual void eat(spPlayerObject other);
        virtual void accelerate(const Vector2& ys, double time);
        double getSize();
        void setSize(double size);
        Vector2 getVelocity();
        void setVelocity(Vector2 velocity);

    protected:
        double _size;
        Vector2 _velocity;
};

#endif
