#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "flow.h"
#include "Scene.h"
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
