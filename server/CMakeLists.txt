cmake_minimum_required(VERSION 2.8)
project(zappy_server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")


include_directories(include)

set(SOURCE_FILES
    src/main.c
        src/set_params.c
        src/utils.c)

add_executable(server ${SOURCE_FILES})