cmake_minimum_required(VERSION 2.8)
project(ece650-cpp-examples)

## ECE650 Specific configuration start here
## Project specific configurations go here

# enable c++11 support
set (CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")

# create the main executable
## add additional .cpp files if needed
add_executable(example example.cpp)
add_executable(example2 example2.cpp)
add_executable(complex_main complex_main.cpp)
add_executable(list list.cpp)
add_executable(stack stack.cpp)
add_executable(using_pipe using_pipe.cpp)
add_executable(using_getopt using_getopt.cpp)
add_executable(using_rand using_rand.cpp)

# create the executable for tests
add_executable(tests test.cpp)
