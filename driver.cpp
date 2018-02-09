#include <iostream>
#include <stdio.h>
#include "chess_board/chess_board.h"
#include "Algorthims/Warnsdorffs/Warnsdorffs.h"
#include "utils/Stack/Stack.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define  n 8

void testing(){


    chess_board * board_controls = new chess_board(n,n);
    int ** the_board = board_controls->getBoard();
    Warnsdroffs * warnsdroff =  new Warnsdroffs(the_board);
    int row = 0, col =0;

    board_controls->move(row,col);

    while(board_controls->number_of_moves() < 32)
        warnsdroff->nextMove(board_controls);

    board_controls->printBoard();

    while(board_controls->number_of_moves() > 1)
        board_controls->backtrack();

    board_controls->printBoard();
}

// Driver code
int main()
{
    bool debug = true;
    // To make sure that different random
    // initial positions are picked.
    srand(time(NULL));

    chess_board * board_controls = new chess_board(n,n);
    int ** the_board = board_controls->getBoard();
    Warnsdroffs * warnsdroff =  new Warnsdroffs(the_board);
    int row = 0, col =0;

    if(!debug) {
        std::cout << "||| Enter the initial position of the knight |||\n";
        std::cout << "||| Enter the row: ";
        std::cin >> row;
        std::cout << "||| Enter the column: ";
        std::cin >> col;
    }

    board_controls->move(row,col);

    while(board_controls->number_of_moves() < 32)
        warnsdroff->nextMove(board_controls);

    board_controls->printBoard();

    return 0;
}
