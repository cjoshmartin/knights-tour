#include <iostream>
#include "chess_board.h"


int main() {
    chess_board * main_board = new chess_board(8,8);
    int ** control_board = main_board->getBoard();

    control_board[0][0]= 2;
    control_board[4][4] =9;
    
    main_board->printBoard();
    std::cout << std::endl;

    return 0;
}