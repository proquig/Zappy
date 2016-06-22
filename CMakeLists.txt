cmake_minimum_required(VERSION 2.8)
project(zappy_server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")


include_directories(server/include)
include_directories(common/include)

file(
    GLOB_RECURSE
    SOURCES
    common/src/*.c
    server/src/*.c
)

add_executable(server ${SOURCES})