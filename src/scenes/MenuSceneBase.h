#ifndef __MENU_SCENE_BASE_H__
#define __MENU_SCENE_BASE_H__

#include "Scene.h"
#include "../controls/menu.h"

class MenuSceneBase : public flow::Scene
{
    public:
        MenuSceneBase();
        virtual ~MenuSceneBase();

    protected:
        spActor _scene;
        spMenu _menu;
};

#endif
