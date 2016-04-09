#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "flow/flow.h"
#include "flow/Scene.h"
#include "../../Controls/menu.h"

DECLARE_SMART(MainMenuScene, spMainMenuScene);

class MainMenuScene : public flow::Scene
{
    public:
        MainMenuScene();
    private:
        spActor _scene;
        spMenu _menu;
};

#endif
