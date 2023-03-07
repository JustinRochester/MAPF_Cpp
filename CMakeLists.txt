cmake_minimum_required(VERSION 3.24)
project(MAPF_Cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc")
include_directories("src")
include_directories("unit_test")

set(common_file inc/common.h src/common.cpp)
set(Position_file inc/Position.h src/Position.cpp ${common_file})
set(Map_file inc/Map.h src/Map.cpp ${common_file} ${Position_file})
set(MapReader_file inc/MapReader.h src/MapReader.cpp ${common_file} ${Position_file} ${Map_file})
set(HeuristicMap_file inc/HeuristicMap.h src/HeuristicMap.cpp ${common_file} ${Position_file} ${Map_file})

set(State_file inc/State.h src/State.cpp)
set(SingleAgentState_file inc/SingleAgentState.h src/SingleAgentState.cpp ${Position_file} ${State_file})
set(MultiAgentState_file inc/MultiAgentState.h src/MultiAgentState.cpp ${Position_file} ${State_file})

set(Node_file inc/Node.h src/Node.cpp ${common_file})
set(Solver_file inc/Solver.h src/Solver.cpp ${common_file} ${Position_file} ${Map_file} ${Node_file})
set(OpenList_file inc/OpenList.h src/OpenList.cpp ${Node_file})
set(CloseList_file inc/CloseList.h src/CloseList.cpp ${State_file})

set(AStarNode_file inc/AStarNode.h src/AStarNode.cpp ${common_file} ${MultiAgentState_file} ${Position_file} ${Node_file})
set(AStar_file inc/AStar.h src/AStar.cpp ${Solver_file} ${HeuristicMap_file} ${AStarNode_file} ${OpenList_file} ${CloseList_file})



set(common_test ${common_file} unit_test/commonTester.h src/SingleAgentState.cpp)
add_executable(common main.cpp ${common_test})

set(Position_test ${Position_file} unit_test/PositionTester.h)
add_executable(Position main.cpp ${Position_test})

set(Node_test ${Node_file} unit_test/NodeTester.h)
add_executable(Node main.cpp ${Node_test})

set(Map_test ${Map_file} unit_test/MapTester.h)
add_executable(Map main.cpp ${Map_test})

set(MapReader_test ${MapReader_file} unit_test/MapReaderTester.h)
add_executable(MapReader main.cpp ${MapReader_test})

set(HeuristicMap_test ${HeuristicMap_file} unit_test/HeuristicMapTester.h)
add_executable(HeuristicMap main.cpp ${HeuristicMap_test} ${MapReader_test})

set(SingleAgentState_test ${SingleAgentState_file} unit_test/SingleAgentStateTester.h)
add_executable(SingleAgentState main.cpp ${SingleAgentState_test})