cmake_minimum_required(VERSION 2.8)

project(game C)
include(CTest)

set(CMAKE_C_FLAGS "-std=c99 -g -Wall")

#add_library(game ftg.c)
add_executable(ftg ftg.c)

#target_link_libraries(ftg ftg)