//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include <iostream>
#include "chess_board.h"

chess_board::chess_board(int rows, int col) : _chessboard(0), _row(rows),_col(col) {

    _chessboard = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        _chessboard[i] = new int[col]; // creating the columns
        for (int j=0; j< col; j++)
        {
            _chessboard[i][j] = -1; // setting the init value
        }
    }

    postion_stack = new Stack();
}

chess_board::~chess_board(void) {

    for (int i = 0; i < _row; ++i)
       delete [] _chessboard[i];

    delete [] _chessboard;

}

int **chess_board::getBoard() {
    return _chessboard;
}

void chess_board::printBoard() {

    for (int i = 0; i <= _row; i++) {
        for (int j=0; j<= _col; j++)
        {
            if(i==0 && j!=0 )
                printf("%2c ",65 + (j-1)); // genrates  Upcase letter by using ASCII values

            else if(j==0)
                ((i-1) < 0 )? printf("%2c%c ", 42,32) : printf("%2d| ", (i - 1)); // prints grid index
            else
//                if(_chessboard[i-1][j-1] == 1)
//                    printf("%2c ",42);
//                else if (_chessboard[i-1][j-1] >= 2)
//                    printf("%2c ",'X');
//                else
                printf("%2d ", _chessboard[i-1][j-1]); // prints if postion has been visited
        }
        std::cout << std::endl;
    }
}

void chess_board::move(int row, int col) {

    if(row >_row)
        throw std::invalid_argument("Invalid attempt set row");

    if(col >_col)
        throw std::invalid_argument("Invalid attempt set col");

    _chessboard[row][col]= ++_number_of_moves;

    postion_stack->push(new postion(row,col));

//    _chessboard[row][col] = (_chessboard[row][col] == -1 ) ? 1 : ++_chessboard[row][col];
    printf("\n you have moved to (%c,%d)\n",65+(row),col);
    this->printBoard();

}
