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

chess_board::chess_board(int rows, int col) {

    _row = rows;
    _col = col;

    _chessboard = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        _chessboard[i] = new int[col]; // creating the columns
        for (int j=0; j< col; j++)
        {
            _chessboard[i][j] = -1; // setting the init value
        }
    }
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

    std::cout << "\n";

    for (int i = 0; i < _row; ++i) {
        for (int j=0; j< _col; j++)
        {
            printf("%2d ", _chessboard[i][j]);
        }
        std::cout << std::endl;
    }
}

void chess_board::move(int row, int col) {
    _chessboard[row][col] = (_chessboard[row][col] == -1 ) ? 1 : _chessboard[row][col]++;
}
