cmake_minimum_required(VERSION 3.5)
project(masters_fsm)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

Find_Package(SDL REQUIRED)
Find_Package(SDL_image REQUIRED)
Find_Package(SDL_ttf REQUIRED)
Find_Package(SDL_gfx REQUIRED)

add_definitions(-D_DEBUG -D_LINUX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

link_libraries(
        ${SDL_LIBRARY}
        ${SDLIMAGE_LIBRARY}
        ${SDLTTF_LIBRARY}
        ${SDLGFX_LIBRARY}
        SDLmain
)

file(GLOB CLASSES_SRC "Classes/*.h" "Classes/*.cpp")
file(GLOB UTILS_SRC "Classes/Utils/*.h" "Classes/Utils/*.cpp")
file(GLOB RAPID_SRC1 "Classes/Utils/rapidjson/*.h" "Classes/Utils/rapidjson/*.cpp")
file(GLOB RAPID_SRC2 "Classes/Utils/rapidjson/*/*.h" "Classes/Utils/rapidjson/*/*.cpp")
file(GLOB LOCATIONS_SRC "Classes/Locations/*.h" "Classes/Locations/*.cpp")
file(GLOB PATHFINDING_SRC "Classes/Pathfinding/*.h" "Classes/Pathfinding/*.cpp")
file(GLOB AI_SRC "Classes/AI/*.h" "Classes/AI/*.cpp")
file(GLOB AI_ACTIONS_SRC "Classes/AI/Actions/*.h" "Classes/AI/Actions/*.cpp")
file(GLOB AI_SM_SRC "Classes/AI/State_Machines/*.h" "Classes/AI/State_Machines/*.cpp")
file(GLOB AI_SM_DEFAULT_SRC "Classes/AI/State_Machines/Default/*/*.h" "Classes/AI/State_Machines/Default/*/*.cpp")
file(GLOB AI_SM_RV2_SRC "Classes/AI/State_Machines/Rand_V2/*/*.h" "Classes/AI/State_Machines/Rand_V2/*/*.cpp")
file(GLOB AI_SM_RV3_SRC "Classes/AI/State_Machines/Rand_V3/*/*.h" "Classes/AI/State_Machines/Rand_V3/*/*.cpp")
file(GLOB AI_SM_RV4_SRC "Classes/AI/State_Machines/Rand_V4/*/*.h" "Classes/AI/State_Machines/Rand_V4/*/*.cpp")
file(GLOB AI_SM_SQV1_SRC "Classes/AI/State_Machines/Squad_V1/*/*.h" "Classes/AI/State_Machines/Squad_V1/*/*.cpp")
file(GLOB AI_SM_SQV2_SRC "Classes/AI/State_Machines/Squad_V2/*/*.h" "Classes/AI/State_Machines/Squad_V2/*/*.cpp")
file(GLOB AI_SM_SQV3_SRC "Classes/AI/State_Machines/Squad_V3/*/*.h" "Classes/AI/State_Machines/Squad_V3/*/*.cpp")
file(GLOB AI_SM_SQV4_SRC "Classes/AI/State_Machines/Squad_V4/*/*.h" "Classes/AI/State_Machines/Squad_V4/*/*.cpp")
file(GLOB AI_SM_SQV5_SRC "Classes/AI/State_Machines/Squad_V5/*/*.h" "Classes/AI/State_Machines/Squad_V5/*/*.cpp")
file(GLOB AI_SM_HTN_SRC "Classes/AI/State_Machines/Htn_V1/*/*.h" "Classes/AI/State_Machines/Htn_V1/*/*.cpp")
file(GLOB AI_PLANNER_SRC "Classes/AI/Planner/*.h" "Classes/AI/Planner/*.cpp")
file(GLOB AI_PLANNER_DIR_SRC "Classes/AI/Planner/*/*.h" "Classes/AI/Planner/*/*.cpp")

set(SOURCE_FILES main.cpp ${CLASSES_SRC} ${UTILS_SRC} ${RAPID_SRC1} ${RAPID_SRC2} ${LOCATIONS_SRC} ${PATHFINDING_SRC}
        ${AI_SRC} ${AI_ACTIONS_SRC}
        ${AI_SM_SRC} ${AI_SM_DEFAULT_SRC} ${AI_SM_RV2_SRC} ${AI_SM_RV3_SRC} ${AI_SM_RV4_SRC}
        ${AI_SM_SQV1_SRC} ${AI_SM_SQV2_SRC} ${AI_SM_SQV3_SRC} ${AI_SM_SQV4_SRC} ${AI_SM_SQV5_SRC} ${AI_SM_HTN_SRC}
        ${AI_PLANNER_SRC} ${AI_PLANNER_DIR_SRC})

add_executable(masters_fsm ${SOURCE_FILES})