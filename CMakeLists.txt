cmake_minimum_required(VERSION 3.13)
project(Green_vs__Red)

set(CMAKE_CXX_STANDARD 14)

add_executable(Green_vs__Red main.cpp Grid.h GridReader.h Grid.cpp GridReader.cpp GridDimensions.cpp GenerationGenerator.h GenerationGenerator.cpp GreenVsRedEngine.h GreenVsRedEngine.cpp)