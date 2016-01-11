#ifndef __MENU_SCENE_BASE_H__
#define __MENU_SCENE_BASE_H__

#include "oxygine-framework.h"
#include "Scene.h"
#include "../controls/menu.h"


class MenuSceneBase : public flow::Scene
{
    public:
        MenuSceneBase(){
            _actor = new Actor;
            _actor->attachTo(_holder);
            _menu = new Menu(Vector2(getStage()->getSize().x / 2, 200));
            _menu->addToActor(_actor);
        }
    protected:
        spActor _actor;
        spMenu _menu;
};

#endif


