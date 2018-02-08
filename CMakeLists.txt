cmake_minimum_required(VERSION 3.9)
project(knigths_tours)

set(CMAKE_CXX_STANDARD 11)

add_executable(knigths_tours driver.cpp chess_board.cpp chess_board.h postion.h Warnsdorffs.cpp Warnsdorffs.h postion.cpp)