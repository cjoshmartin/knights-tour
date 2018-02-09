#include <iostream>
#include "chess_board/chess_board.h"
#include "Algorthims/Warnsdorffs/Warnsdorffs.h"
#include "Algorthims/DepthFirst/DepthFirst.h"

#define  n 8

void first_move( chess_board * board_controls,bool debug){
    int row =0, col =0;

    if(!debug) {
        std::cout << "||| Enter the initial position of the knight |||\n";
        std::cout << "||| Enter the row: ";
        std::cin >> row;
        std::cout << "||| Enter the column: ";
        std::cin >> col;
    }

    board_controls->move(row,col,-1);
}

void testing(){


    chess_board * board_controls = new chess_board(n,n);
    Warnsdroffs * warnsdroff =  new Warnsdroffs(board_controls->getBoard(),board_controls);

    first_move(board_controls,false);

    while(board_controls->number_of_moves() < 32)
        warnsdroff->algorthim();

    board_controls->printBoard();

    while(board_controls->number_of_moves() > 1)
        board_controls->backtrack();

    board_controls->printBoard();
}

// Driver code
int main()
{
    bool debug = true;

    chess_board * board_controls =     new chess_board(n,n);

    Warnsdroffs * warnsdroff     =     new Warnsdroffs(board_controls->getBoard(),board_controls);
    DepthFirst  * depthfirst     =     new DepthFirst(board_controls->getBoard(),board_controls);

    first_move(board_controls,debug);

do {
    while (board_controls->number_of_moves() < 32)
        warnsdroff->algorthim();

    while(board_controls->number_of_moves() >= 32 & board_controls->number_of_moves() < 64)
       depthfirst->algorthim();

}while (board_controls->number_of_moves() < 64);

    board_controls->printBoard();
    return 0;
}
