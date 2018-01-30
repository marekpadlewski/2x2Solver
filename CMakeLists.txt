cmake_minimum_required(VERSION 3.8)
project(2x2_Solver)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_C_COMPILER "clang")
#set(CMAKE_CXX_COMPILER "clang++")

set(common_flags "-O3 -Wall -Wextra -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${common_flags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${common_flags}")


set(SOURCE_FILES Moves.h Moves.c CubeState.h CubeState.c SolutionsFinder.c SolutionsFinder.h
        UserInputParsing.h UserInputParsing.c StatesComputor.c StatesComputor.h CyclicBuffer.c CyclicBuffer.h
        CubeStateMap.cpp CubeStateMap.h CubeStatesReaderWriter.c CubeStatesReaderWriter.h)

add_executable(2x2_Solver main.c ${SOURCE_FILES})