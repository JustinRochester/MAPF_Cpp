cmake_minimum_required(VERSION 3.24)
project(MAPF_Cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc")
include_directories("src")
include_directories("unit_test")

set(common_file inc/common.h src/common.cpp)
set(common_test ${common_file} unit_test/commonTester.h)
add_executable(common main.cpp ${common_test})

set(Node_file inc/Node.h src/Node.cpp ${common_file})
set(Node_test ${Node_file} unit_test/NodeTester.h)
add_executable(Node main.cpp ${Node_test})