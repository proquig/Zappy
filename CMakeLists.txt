cmake_minimum_required(VERSION 3.5)
project(server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")


include_directories(include)

set(SOURCE_FILES
    server/src/main.c
        server/src/utils.c)

add_executable(server ${SOURCE_FILES})