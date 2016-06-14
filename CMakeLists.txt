cmake_minimum_required(VERSION 2.8)
project(zappy_server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra")


include_directories(server/include)

set(SOURCE_FILES
        server/src/main.c
        server/src/set_params.c
        server/src/utils.c)

add_executable(server ${SOURCE_FILES})