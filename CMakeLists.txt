cmake_minimum_required(VERSION 3.5)
project(PSU_2015_zappy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    binaries/zappy-gfx-linux64.tgz
    binaries/zappy-server-linux
    subject/graphical-client-protocol/protocole-client-graphique.pdf
    subject/zappy.pdf)

add_executable(PSU_2015_zappy ${SOURCE_FILES})