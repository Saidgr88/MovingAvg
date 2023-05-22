cmake_minimum_required(VERSION 3.5)
project(MovingAvg )

#set(CMAKE_1_COMPILER clang++)
set(PROJECT_SOURCES
		main.cpp
		movingAvg.h
		movingAvg.cpp)
add_executable(movingAvg ${PROJECT_SOURCES})



