cmake_minimum_required (VERSION 2.6)
project (EatingCircles)

add_subdirectory(../../oxygine/oxygine-framework/ oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})

add_subdirectory(../../oxygine/oxygine-flow oxygine-flow)
include_directories(${OXYGINE_FLOW_INCLUDE_DIRS})

SET(CMAKE_EXECUTABLE_SUFFIX ".html")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " -std=c++11")

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
        ../src/Game/Model/Unit.cpp
        ../src/Game/Model/UnitController/AI.cpp
        ../src/Game/Model/UnitController/UnitController.cpp
        ../src/Game/Presenter/GamePresenter.cpp
        ../src/Game/View/GameView.cpp
        ../src/Game/View/Gui/Circle.cpp
        ../src/Game/View/Gui/Packman.cpp
        ../src/Game/View/Gui/GuiObject.cpp
        ../src/Game/View/Gui/GuiController.cpp
        ../src/Game/View/ExtraObjects/star.cpp

        ../src/Controls/menu.cpp
)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
	SET(linkFlags "-g4 ")
else() # Either MinSizeRel, RelWithDebInfo or Release, all which run with optimizations enabled.
	SET(linkFlags "-O2 ")
endif()

set(linkFlags "${linkFlags} -s NO_EXIT_RUNTIME=1 -s FULL_ES2=1 -s WARN_ON_UNDEFINED_SYMBOLS=1 --memory-init-file 0 -s TOTAL_MEMORY=50331648")

set_target_properties(EatingCircles PROPERTIES LINK_FLAGS "${linkFlags}")

target_link_libraries(EatingCircles ${OXYGINE_CORE_LIBS}  oxygine-flow) 
em_link_pre_js(EatingCircles  ${OXYGINE_JS_LIBRARIES} ${CMAKE_CURRENT_SOURCE_DIR}/data.js)
