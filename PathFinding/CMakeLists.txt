cmake_minimum_required(VERSION 2.6)

project(pathfindr)

file(GLOB sources *.cpp)

add_executable(run ${sources})
