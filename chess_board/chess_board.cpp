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

chess_board::chess_board(int rows, int col) : _chessboard(0), _row(rows),_col(col), _number_of_moves(0)  {

    _chessboard = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        _chessboard[i] = new int[col]; // creating the columns
        for (int j=0; j< col; j++)
        {
            _chessboard[i][j] = -1; // setting the init value
        }
    }

    _postion_stack = new Stack();
}

chess_board::~chess_board(void) {

    for (int i = 0; i < _row; ++i)
       delete [] _chessboard[i];

    delete [] _chessboard;

}


size_t chess_board::number_of_moves(){
    return _number_of_moves;
}

int **chess_board::getBoard() const {
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
                printf("%2d ", _chessboard[i-1][j-1]); // prints if position has been visited
        }
        std::cout << std::endl;
    }
}

void chess_board::move(int row, int col, int pre_postion_index) {

    if(row >_row && row  < 0)
        throw std::invalid_argument("Invalid attempt set row");

    if(col >_col && col < 0)
        throw std::invalid_argument("Invalid attempt set col");

    if (_postion_stack->size() > 0)
    _postion_stack->top()->set_position_index(pre_postion_index);  // set the index of the point on top, so that if I need to comeback I don't need to check all points

    _chessboard[row][col]= ++_number_of_moves; // will count the numbers of moves and set that to the positon in the array

    _postion_stack->push(new postion(row,col));

//    _chessboard[row][col] = (_chessboard[row][col] == -1 ) ? 1 : ++_chessboard[row][col];
    printf("\n you have moved to (%c,%d)\n", 65 + row, col);
}

void chess_board::backtrack() {
    postion * to_remove = _postion_stack->top();
    int row = to_remove->get_row(), col = to_remove->get_col();
    --_number_of_moves;

    _chessboard[row][col] = -1;
    _postion_stack->pop();
    printf("\n you backtracked from (%c,%d) to (%c,%d) \n", 65 + row, col, 65 + _postion_stack->top()->get_row(), _postion_stack->top()->get_col());
}

postion chess_board::current_position() {
    return *_postion_stack->top();
}

