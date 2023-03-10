cmake_minimum_required(VERSION 3.24)
project(MAPF_Cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        "inc"
        "inc/base"
        "inc/states"
        "inc/solver_base"
        "inc/naive_AStar"
        "inc/ID_AStar"
        )
include_directories(
        "src"
        "src/base"
        "src/states"
        "src/solver_base"
        "src/naive_AStar"
        "src/ID_AStar"
        )
include_directories(
        "unit_test"
        "unit_test/base"
        "unit_test/states"
        "unit_test/solver_base"
        "unit_test/naive_AStar"
        "unit_test/ID_AStar"
        )

set(common_file inc/base/common.h src/base/common.cpp)
set(Position_file inc/base/Position.h src/base/Position.cpp ${common_file})
set(PositionList_file inc/base/PositionList.h src/base/PositionList.cpp ${Position_file})
set(Map_file inc/base/Map.h src/base/Map.cpp ${common_file} ${Position_file})
set(MapReader_file inc/base/MapReader.h src/base/MapReader.cpp ${common_file} ${Position_file} ${Map_file})
set(HeuristicMap_file inc/base/HeuristicMap.h src/base/HeuristicMap.cpp ${common_file} ${Position_file} ${Map_file})
set(AgentPath_file inc/base/AgentPath.h src/base/AgentPath.cpp ${PositionList_file})

set(State_file inc/states/State.h src/states/State.cpp)
set(SingleAgentState_file inc/states/SingleAgentState.h src/states/SingleAgentState.cpp ${Position_file} ${State_file})
set(MultiAgentState_file inc/states/MultiAgentState.h src/states/MultiAgentState.cpp ${Position_file} ${State_file} ${PositionList_file})

set(Node_file inc/solver_base/Node.h src/solver_base/Node.cpp ${common_file})
set(CloseList_file inc/solver_base/CloseList.h src/solver_base/CloseList.cpp ${State_file})
set(OpenList_file inc/solver_base/OpenList.h src/solver_base/OpenList.cpp ${Node_file})
set(Solver_file inc/solver_base/Solver.h src/solver_base/Solver.cpp ${common_file} ${Position_file} ${Map_file} ${Node_file})

set(AStarNode_file inc/naive_AStar/AStarNode.h src/naive_AStar/AStarNode.cpp ${common_file} ${MultiAgentState_file} ${Position_file} ${Node_file})
set(AStar_file inc/naive_AStar/AStar.h src/naive_AStar/AStar.cpp ${Solver_file} ${HeuristicMap_file} ${AStarNode_file} ${OpenList_file} ${CloseList_file})

set(IndependenceDetection_file inc/ID_AStar/IndependenceDetection.h src/ID_AStar/IndependenceDetection.cpp)



set(common_test ${common_file} unit_test/base/commonTester.h src/states/SingleAgentState.cpp)
add_executable(common main.cpp ${common_test})

set(Position_test ${Position_file} unit_test/base/PositionTester.h)
add_executable(Position main.cpp ${Position_test})

set(PositionList_test ${PositionList_file} unit_test/base/PositionListTester.h)
add_executable(PositionList main.cpp ${PositionList_test})

set(Map_test ${Map_file} unit_test/base/MapTester.h)
add_executable(Map main.cpp ${Map_test})

set(MapReader_test ${MapReader_file} unit_test/base/MapReaderTester.h)
add_executable(MapReader main.cpp ${MapReader_test})

set(HeuristicMap_test ${HeuristicMap_file} unit_test/base/HeuristicMapTester.h)
add_executable(HeuristicMap main.cpp ${HeuristicMap_test} ${MapReader_test})

set(AgentPath_test ${AgentPath_file} unit_test/base/AgentPathTester.h)
add_executable(AgentPath main.cpp ${AgentPath_test})

set(SingleAgentState_test ${SingleAgentState_file} unit_test/states/SingleAgentStateTester.h)
add_executable(SingleAgentState main.cpp ${SingleAgentState_test})

set(MultiAgentState_test ${MultiAgentState_file} unit_test/states/MultiAgentStateTester.h)
add_executable(MultiAgentState main.cpp ${MultiAgentState_test})

set(Node_test ${Node_file} unit_test/solver_base/NodeTester.h)
add_executable(Node main.cpp ${Node_test})

set(CloseList_test ${CloseList_file} unit_test/solver_base/CloseListTester.h)
add_executable(CloseList main.cpp ${CloseList_test} ${SingleAgentState_test})

set(AStarNode_test ${AStarNode_file} unit_test/naive_AStar/AStarNodeTester.h)
add_executable(AStarNode main.cpp ${AStarNode_test})

set(OpenList_test ${OpenList_file} unit_test/solver_base/OpenListTester.h)
add_executable(OpenList main.cpp ${OpenList_test} ${AStarNode_file})

set(AStar_test ${AStar_file} unit_test/naive_AStar/AStarTester.h)
add_executable(AStar main.cpp ${AStar_test} ${MapReader_file})

set(IndependenceDetection_test ${IndependenceDetection_file} unit_test/ID_AStar/IndependenceDetectionTester.h)
add_executable(IndependenceDetection main.cpp ${IndependenceDetection_test} ${MapReader_file})