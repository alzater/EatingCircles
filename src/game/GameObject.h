#include "oxygine-framework.h"

using namespace oxygine;

class GameObject
{
    public:
        GameObject(Vector2 startPosition);
        virtual ~GameObject();

        virtual void move(const Vector2& deltaPosition) = 0;
        bool isInRectangle(Vector2 start, Vector2 end);
        void setPosition(const Vector2& position);
        const Vector2& getPosition();

    protected:
        Vector2 _position;
};
