#include "oxygine-framework.h"

using namespace oxygine;

class GameObject : public EventDispatcher
{
    public:
        GameObject(const Vector2& startPosition);
        virtual ~GameObject();

        virtual void move(const Vector2& deltaPosition) = 0;
        bool isInRectangle(const Vector2& start, const Vector2& end);
        void setPosition(const Vector2& position);
        const Vector2& getPosition();

    protected:
        Vector2 _position;
};
