include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} )

add_executable(runTourTest
        basic_check.cpp)

target_link_libraries(runTourTest gtest gtest_main)
target_link_libraries(runTourTest tour)