#ifndef __UNIT_CONTROLLER_H__
#define __UNIT_CONTROLLER_H__

#include "oxygine-framework.h"
#include "../Game.h"

using oxygine::Object;

class UnitController : public Object
{
public:
    UnitController(spGame game);
    virtual ~UnitController();

    virtual void makeTurn() = 0;
private:
    spGame _game;
};
DECLARE_SMART(UnitController, spUnitController)

#endif
