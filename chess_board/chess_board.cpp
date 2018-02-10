//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include <iostream>
#include <fstream>
#include <vector>
#include "chess_board.h"
#include "../utils/string_formater.h"
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

    _moves_stringstream = "";
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

void chess_board::printToFile(std::string file) {

    std::ofstream output_file(file);
    output_file << _moves_stringstream;
    output_file.close();
}


void chess_board::printToScreen() {
        std::cout << _moves_stringstream;
}


std::string chess_board::printBoard(bool append) {

    std::string board_string ="\n";
    for (int i = 0; i <= _row; i++) {
        for (int j=0; j<= _col; j++)
        {
            if(i==0 && j!=0 )
               board_string += string_formater::formater("%2c ",65 + (j-1)); // generates  Upcase letter by using ASCII values

            else if(j==0)
                ((i-1) < 0 )? board_string += string_formater::formater("%2c%c ", 42,32) : board_string += string_formater::formater("%2d| ", (i - 1)); // prints grid index
            else
                board_string += string_formater::formater("%2d ", _chessboard[i-1][j-1]); // prints if position has been visited
        }
        board_string+= "\n";
    }
    if (append)
    _moves_stringstream += board_string;
    return board_string;
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

    std::string move_strings = string_formater::formater("\n you have moved to (%c,%d)\n", 65 + row, col);
    saveStringStream(move_strings);
}

void chess_board::backtrack() {
    postion * to_remove = _postion_stack->top();
    int row = to_remove->get_row(), col = to_remove->get_col();
    --_number_of_moves;

    _chessboard[row][col] = -1;
    _postion_stack->pop();
    std::string move_strings = string_formater::formater("\n you backtracked from (%c,%d) to (%c,%d) \n", 65 + row, col,
                                        65 + _postion_stack->top()->get_row(), _postion_stack->top()->get_col());
    saveStringStream(move_strings);
}

postion chess_board::current_position() {
    return *_postion_stack->top();
}


void chess_board::saveStringStream(std::string streamer) {

    std::cout << streamer;
    _moves_stringstream += streamer;
}


