cmake_minimum_required(VERSION 3.24)
project(MAPF_Cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc")
include_directories("src")

add_executable(MAPF_Cpp main.cpp
        src/AStar.cpp src/AStarNode.cpp src/CloseList.cpp src/common.cpp src/HeuristicMap.cpp src/Map.cpp src/MapReader.cpp src/MultiAgentState.cpp src/Node.cpp src/OpenList.cpp src/Position.cpp src/SingleAgentState.cpp src/Solver.cpp src/State.cpp inc/AStar.h inc/AStarNode.h inc/CloseList.h inc/common.h inc/HeuristicMap.h inc/Map.h inc/MapReader.h inc/MultiAgentState.h inc/Node.h inc/OpenList.h inc/Position.h inc/SingleAgentState.h inc/Solver.h inc/State.h)

add_executable(main
        src/AStar.cpp src/AStarNode.cpp src/CloseList.cpp src/common.cpp src/HeuristicMap.cpp src/Map.cpp src/MapReader.cpp src/MultiAgentState.cpp src/Node.cpp src/OpenList.cpp src/Position.cpp src/SingleAgentState.cpp src/Solver.cpp src/State.cpp inc/AStar.h inc/AStarNode.h inc/CloseList.h inc/common.h inc/HeuristicMap.h inc/Map.h inc/MapReader.h inc/MultiAgentState.h inc/Node.h inc/OpenList.h inc/Position.h inc/SingleAgentState.h inc/Solver.h inc/State.h)
