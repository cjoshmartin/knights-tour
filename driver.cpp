#include <iostream>
#include <stdio.h>
#include "chess_board.h"
#include "Warnsdorffs.h"
#include "Stack.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define  n 8
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
    Stack<postion> * postion_stack = new Stack<postion>();
    postion current ;

    if(!debug) {
        std::cout << "||| Enter the initial position of the knight |||\n";
        std::cout << "||| Enter the row: ";
        std::cin >> current->row;
        std::cout << "||| Enter the column: ";
        std::cin >> current->col;
    }
    if (debug){ current.row= 0; current.col = 0;}

    postion_stack->push(&current);

    the_board[current.row][current.col] = 1; // Mark first move.

    for(size_t i =0; i < 31; i++)
        warnsdroff->nextMove(&current->row, &current->col);

    board_controls->printBoard();
    return 0;
}
