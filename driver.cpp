#include <iostream>
#include "chess_board.h"
#include "State.h"


int main() {
    State * head = new State();
    postion current = head->current_position;

    chess_board * main_board = new chess_board(8,8);
    int ** control_board = main_board->getBoard();

    std::cout << "||| Enter the initial postion of the knight |||\n";
    std::cout << "||| Enter the row: ";
    std::cin >> current.row;
    std::cout << "||| Enter the column: ";
    std::cin >> current.col;

    main_board->move(current.row,current.col);

    main_board->printBoard();
    std::cout << std::endl;

    return 0;
}