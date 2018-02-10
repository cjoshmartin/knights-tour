cmake_minimum_required(VERSION 3.9)
project(knigths_tours)

set(CMAKE_CXX_STANDARD 11)

add_executable(knigths_tours driver.cpp chess_board/chess_board.cpp chess_board/chess_board.h utils/postion/postion.h utils/Stack/Stack.cpp utils/Stack/Stack.h Algorthims/Warnsdorffs/Warnsdorffs.cpp Algorthims/Warnsdorffs/Warnsdorffs.h utils/postion/postion.cpp Algorthims/DepthFirst/DepthFirst.cpp Algorthims/DepthFirst/DepthFirst.h Algorthims/Algorthims.cpp Algorthims/Algorthims.h utils/string_formater.cpp utils/string_formater.h)