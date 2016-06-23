cmake_minimum_required(VERSION 3.5)
project(client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(SOURCE_FILES
        src/Client.cpp
        src/get_command.cpp
        src/IA.cpp
        src/main.cpp
        src/utils.cpp)

add_executable(client ${SOURCE_FILES})