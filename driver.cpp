#include <iostream>
#include "chess_board.h"
#include "State.h"

#define Max_Rows 8
#define Max_Cols  8

int can_move(int row,int col, int ** control_board)
{
    return control_board[row][col]== -1;
}

int main() {
    State * head = new State();
    postion current = head->current_position;

    chess_board * main_board = new chess_board(Max_Rows,Max_Cols);
    int ** control_board = main_board->getBoard();

    std::cout << "||| Enter the initial postion of the knight |||\n";
    std::cout << "||| Enter the row: ";
    std::cin >> current.row;
    std::cout << "||| Enter the column: ";
    std::cin >> current.col;

    main_board->move(current.row,current.col);


    int move_row, move_col;
    do {

        move_row = 0;
        move_col = 0  ;
        bool check_neg_col1 = (current.col > 1);
        bool check_if_less_then_max_col1 = (Max_Cols > (current.col +1) );
        bool check_neg_col2 = (current.col > 2);
        bool check_if_less_then_max_col2 = (Max_Cols > (current.col +2) );

        // row: 2
        if (current.row > 2) {
            // (i − 2,j + 1)
            if (can_move(current.row - 2, current.col + 1, control_board) && check_if_less_then_max_col1) {
                move_row = -2;
                move_col = 1;
            }
                // (i−2,j −1)
            else if (can_move(current.row - 2, current.col - 1, control_board) && check_neg_col1) {
                move_row = -1;
                move_col = -1;
            }
        }
        else if(Max_Rows > (current.row +2)) {
            // (i+2,j +1)
            if (can_move(current.row + 2, current.col + 1, control_board) && check_if_less_then_max_col1) {
                move_row = 2;
                move_col = 1;
            }
                // (i+2,j −1),
            else if (can_move(current.row + 2, current.col - 1, control_board) && check_neg_col1) {
                move_row = 2;
                move_col = -1;
            }
        }
            //row: 1
        else if (current.row > 1) {
            // (i−1,j +2),
            if (can_move(current.row - 1, current.col + 2, control_board) && check_if_less_then_max_col2) {
                move_row = -1;
                move_col = 2;
            }
                // (i−1,j −2),
            else if (can_move(current.row - 1, current.col - 2, control_board) && check_neg_col2) {
                move_row = -1;
                move_col = -2;
            }
        }

        else if(Max_Rows > (current.row + 1 )) {
            // (i+1,j −2),
            if (can_move(current.row + 1, current.col - 2, control_board) && check_neg_col2) {
                move_row = +1;
                move_col = -2;
            }
                // (i+1,j +2)
            else if (can_move(current.row + 1, current.col + 2, control_board) && check_if_less_then_max_col2) {
                move_row = +1;
                move_col = +2;
            }
        }
        if( move_row != 0 && move_col!=0)
            main_board->move((current.row = current.row + move_row), (current.col = current.col + move_col));

    } while(move_row != 0 && move_col!=0);

    main_board->printBoard();
    std::cout << std::endl;
    return 0;
}