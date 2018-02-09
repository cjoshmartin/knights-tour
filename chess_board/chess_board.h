//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#ifndef KNIGTHS_TOURS_CHRESSBOARD_H
#define KNIGTHS_TOURS_CHRESSBOARD_H


#include "../utils/postion/postion.h"
#include "../utils/Stack/Stack.h"

class chess_board {
public:
    chess_board(int,int);
    ~chess_board(void);
    size_t number_of_moves();
    int ** getBoard(void);
    void backtrack();
    postion current_position();
    void move(int row, int col, int pre_postion_index);
    void printBoard();

private:
    int ** _chessboard;
    int _row,_col;
    int _number_of_moves;
    Stack * _postion_stack;
};


#endif //KNIGTHS_TOURS_CHRESSBOARD_H
