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
#include <stdexcept>
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
    delete _postion_stack;

}


size_t chess_board::number_of_moves(){
    return _number_of_moves;
}

int **chess_board::getBoard() const {
    return _chessboard;
}

void chess_board::printToFile(std::string file) {
    std::ofstream myfile;
      myfile.open (file);
      myfile << _moves_stringstream;
      myfile.close();
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
               board_string += string_formater::formater("%2d ",(j-1)); // generates  Upcase letter by using ASCII values

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

    //TODO

    _postion_stack->push(new postion(row,col));

    std::string move_strings = string_formater::formater("\n you have moved to (%d,%d)\n", col, row);
    saveStringStream(move_strings);
}

void chess_board::backtrack() {
    postion * to_remove = _postion_stack->top();
    int row = to_remove->get_row(), col = to_remove->get_col();
    --_number_of_moves;

    _chessboard[row][col] = -1;
    _postion_stack->pop();
    std::string move_strings = string_formater::formater("\n you backtracked from (%d,%d) to (%d,%d) \n", col, row,
                                         _postion_stack->top()->get_col(), _postion_stack->top()->get_row());
    saveStringStream(move_strings);
}

postion chess_board::current_position() {
    return *_postion_stack->top();
}


void chess_board::saveStringStream(std::string streamer) {

    std::cout << streamer;
    _moves_stringstream += streamer;
}

std::string chess_board::printSuccessfulPath(bool append) {
    if(_number_of_moves < 63)
        throw std::invalid_argument("Path is not done finding");
    std::string path ="";
    postion * current_postion = _postion_stack->top();
    int i =0;
    while (current_postion != NULL && ++i < 63 ){
        int col = current_postion->get_row();
        int row = current_postion->get_col();
        
        if (i % 8 ==0)
        path = string_formater::formater("\n--->(%d,%d)",row,col) + path;
        else
        path = string_formater::formater(" --->(%d,%d)",row,col) + path;

        current_postion = current_postion->next;
    }
    path= "\nSuccessful Path is:\n --->(x,y):\n\n" + path;

    if(append)
        _moves_stringstream += path;

    return path;
}

bool chess_board::is_vaild_move(int col, int row) {
    int tx[8] = {1,1,2,2,-1,-1,-2,-2};
    int ty[8] = {2,-2,1,-1,2,-2,1,-1};

    if (_number_of_moves== 0)
        return true;

    for (int i = 0; i < _row; i++ )
        if(_number_of_moves >0)
            if ((row == _postion_stack->top()->get_row() + tx[i]) && (col == _postion_stack->top()->get_col() + ty[i]) && _chessboard[row][col] < 0)
                return true;
    return false;
}


