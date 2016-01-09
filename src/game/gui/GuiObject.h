#ifndef __GUI_OBJECT_H__
#define __GUI_OBJECT_H__

#include "oxygine-framework.h"

using namespace oxygine;


class GuiObject: public Object
{
  public:
    GuiObject(const Vector2& position, const double size = 0, const Color& color = Color(255, 255, 255));
    virtual ~GuiObject();
    void addTo(spActor actor);

    virtual void update(const Vector2& position, const double size, const Color& color) = 0;

  protected:
    spActor gui;
};

typedef oxygine::intrusive_ptr <GuiObject> spGuiObject;

#endif
