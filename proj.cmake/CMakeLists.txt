cmake_minimum_required (VERSION 2.6)
project (EatingCircles)

add_subdirectory(../../oxygine/oxygine-framework/ oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})

add_subdirectory(../../oxygine/oxygine-flow oxygine-flow)
include_directories(${OXYGINE_FLOW_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(EatingCircles
        ../src/entry_point.cpp
        ../src/Controller.cpp

        ../src/scenes/GameScene/GameScene.cpp
        ../src/scenes/GameScene/GamePauseDialog.cpp
        ../src/scenes/MainMenuScene/MainMenuScene.cpp
        ../src/scenes/MainMenuScene/ConfirmExitDialog.cpp
        ../src/scenes/MainMenuScene/ConfirmNewGameDialog.cpp

        ../src/game/Model/Game.cpp
        ../src/game/Model/GameObject.cpp
        ../src/game/Model/PlayerObject.cpp
        ../src/game/Model/Bot.cpp
        ../src/game/Model/AI.cpp
        ../src/game/Model/Player.cpp
        ../src/game/Presenter/GamePresenter.cpp
        ../src/game/View/gui/Circle.cpp
        ../src/game/View/gui/Packman.cpp
        ../src/game/View/gui/GuiObject.cpp
        ../src/game/View/gui/GuiController.cpp
        ../src/game/View/extraObjects/star.cpp


        ../src/controls/menu.cpp
)

if (WIN32) #disable console mode for VC++
	set_target_properties(EatingCircles PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)

target_link_libraries(EatingCircles ${OXYGINE_CORE_LIBS} oxygine-flow)
