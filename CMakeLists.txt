cmake_minimum_required(VERSION 3.24)
project(MAPF_Cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc")
include_directories("src")

add_executable(MAPF_Cpp main.cpp src/MapReader.cpp inc/MapReader.h inc/Position.h src/Position.cpp src/HeuristicMap.cpp inc/HeuristicMap.h inc/common.h src/Solver.cpp inc/Solver.h src/AStar.cpp inc/AStar.h src/Map.cpp inc/Map.h src/MultiAgentState.cpp inc/MultiAgentState.h src/OpenList.cpp inc/OpenList.h src/common.cpp)

add_executable(main src/MapReader.cpp inc/MapReader.h inc/Position.h src/Position.cpp src/SingleAgentState.cpp inc/SingleAgentState.h src/HeuristicMap.cpp inc/HeuristicMap.h inc/common.h src/Solver.cpp inc/Solver.h src/AStar.cpp inc/AStar.h src/Map.cpp inc/Map.h src/AStarNode.cpp inc/AStarNode.h src/MultiAgentState.cpp inc/MultiAgentState.h src/CloseList.cpp inc/CloseList.h src/Node.cpp inc/Node.h src/OpenList.cpp inc/OpenList.h src/State.cpp inc/State.h src/common.cpp)
