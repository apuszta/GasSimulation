cmake_minimum_required(VERSION 3.9)
project(GasSimulation)

file(GLOB SOURCES src/*.cpp)

add_executable(GasSimulation ${SOURCES} main.cpp)
