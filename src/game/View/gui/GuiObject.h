#ifndef __GUI_OBJECT_H__
#define __GUI_OBJECT_H__

#include "oxygine-framework.h"

using namespace oxygine;


class GuiObject: public Object
{
  public:
    GuiObject(const Vector2& position, const double size = 0, const Color& color = Color(255, 255, 255));
    virtual ~GuiObject();
    void attachTo(spActor actor);

    virtual void update(const Vector2& position, const double size, const Color& color) = 0;
    virtual void updateRotation(Vector2 newPos);
  protected:
    spActor _gui;
    Vector2 _previousPosition;

};

typedef oxygine::intrusive_ptr <GuiObject> spGuiObject;

#endif
