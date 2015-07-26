cmake_minimum_required (VERSION 2.6)
project (EatingCircles)

add_subdirectory(../../oxygine-framework/ oxygine-framework)
add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(EatingCircles  
        ../src/entry_point.cpp 
        ../src/controller.cpp  
        ../src/controller.h 
        ../src/game/circle.cpp  
        ../src/game/circle.h 
        ../src/game/game.cpp  
        ../src/game/game.h 
        ../src/game/star.cpp 
        ../src/game/star.h
        ../src/controls/menu.h
        ../src/controls/menu.cpp
)

if (WIN32) #disable console mode for VC++
	set_target_properties(EatingCircles PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)

target_link_libraries(EatingCircles ${OXYGINE_CORE_LIBS})
