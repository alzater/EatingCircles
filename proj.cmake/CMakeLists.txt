cmake_minimum_required (VERSION 2.6)
project (EatingCircles)

add_subdirectory(../../oxygine/oxygine-framework/ oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})

add_subdirectory(../../oxygine/oxygine-flow oxygine-flow)
include_directories(${OXYGINE_FLOW_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ggdb")
add_executable(EatingCircles
        ../src/entry_point.cpp
        ../src/Controller.cpp

        ../src/Scenes/GameScene/GameScene.cpp
        ../src/Scenes/GameScene/GamePauseDialog.cpp
        ../src/Scenes/MainMenuScene/MainMenuScene.cpp
        ../src/Scenes/MainMenuScene/ConfirmExitDialog.cpp
        ../src/Scenes/MainMenuScene/ConfirmNewGameDialog.cpp

        ../src/Game/Model/Game.cpp
        ../src/Game/Model/GameObject.cpp
        ../src/Game/Model/PlayerObject.cpp
        ../src/Game/Model/Bot.cpp
        ../src/Game/Model/AI.cpp
        ../src/Game/Presenter/GamePresenter.cpp
        ../src/Game/View/GameView.cpp
        ../src/Game/View/Gui/Circle.cpp
        ../src/Game/View/Gui/Packman.cpp
        ../src/Game/View/Gui/GuiObject.cpp
        ../src/Game/View/Gui/GuiController.cpp
        ../src/Game/View/ExtraObjects/star.cpp

        ../src/Controls/menu.cpp
)

if (WIN32) #disable console mode for VC++
	set_target_properties(EatingCircles PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)

target_link_libraries(EatingCircles ${OXYGINE_CORE_LIBS} oxygine-flow)
