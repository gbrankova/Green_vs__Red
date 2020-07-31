cmake_minimum_required(VERSION 3.13)
project(Green_vs__Red)

set(CMAKE_CXX_STANDARD 14)

add_executable(Green_vs__Red main.cpp Grid/Grid.h Grid/GridReader.h Grid/Grid.cpp Grid/GridReader.cpp GenerationGenerator/GenerationGenerator.h GenerationGenerator/GenerationGenerator.cpp GameEngine/GreenVsRedEngine.h GameEngine/GreenVsRedEngine.cpp Common.cpp)