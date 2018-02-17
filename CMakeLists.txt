cmake_minimum_required(VERSION 3.9)
project(knigths_tours)

set(CMAKE_CXX_STANDARD 11)

add_executable(knigths_tours
#        tour/driver.cpp
        tour_test/tour_test_main.cpp
        tour/chess_board/chess_board.cpp
        tour/chess_board/chess_board.h
        tour/utils/postion/postion.h
        tour/utils/Stack/Stack.cpp
        tour/utils/Stack/Stack.h
        tour/Algorthims/Warnsdorffs/Warnsdorffs.cpp
        tour/Algorthims/Warnsdorffs/Warnsdorffs.h
        tour/utils/postion/postion.cpp
        tour/Algorthims/DepthFirst/DepthFirst.cpp
        tour/Algorthims/DepthFirst/DepthFirst.h
        tour/Algorthims/Algorthims.cpp
        tour/Algorthims/Algorthims.h
        tour/utils/string_formater.cpp
        tour/utils/string_formater.h
        )


