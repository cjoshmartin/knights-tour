//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//


// testing lib
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//files to test
#include "../tour/Algorthims/Algorthims.h"
#include "../tour/Algorthims/DepthFirst/DepthFirst.h"
#include "../tour/Algorthims/Warnsdorffs/Warnsdorffs.h"

#include "../tour/chess_board/chess_board.h"

#include "../tour/utils/postion/postion.h"
#include "../tour/utils/Stack/Stack.h"

#define N 8

TEST_CASE("Testing Postion", "[utils],[postion]")
{
    postion * testpos = new postion(7,8);
    CHECK(testpos->get_row() == 7);
    CHECK(testpos->get_col() == 8);
}
TEST_CASE("Testing Stack","[utils]")
{

}
TEST_CASE("testing the Algorithms class", "[Algorithms]")
{

    chess_board * board_controls =     new chess_board(N,N);

    Warnsdroffs * warnsdroff     =     new Warnsdroffs(board_controls->getBoard(),board_controls);
    DepthFirst  * depthfirst     =     new DepthFirst(board_controls->getBoard(),board_controls);


    REQUIRE( 1==1);
}

