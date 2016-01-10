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

        ../src/scenes/GameScene.cpp
        ../src/scenes/MenuSceneBase.cpp
        ../src/scenes/MainMenuScene.cpp
        ../src/scenes/ConfirmDialog.cpp

        ../src/game/Game.cpp
        ../src/game/GameObject.cpp
        ../src/game/PlayerObject.cpp
        ../src/game/gui/Circle.cpp
        ../src/game/gui/Packman.cpp
        ../src/game/gui/GuiObject.cpp
        ../src/game/gui/GuiController.cpp
        ../src/game/Bot.cpp
        ../src/game/AI.cpp
        ../src/game/Player.cpp
        ../src/game/extraObjects/star.cpp

        ../src/controls/menu.cpp
)

if (WIN32) #disable console mode for VC++
	set_target_properties(EatingCircles PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)

target_link_libraries(EatingCircles ${OXYGINE_CORE_LIBS} oxygine-flow)
