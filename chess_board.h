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


#include "postion.h"
#include "Stack.h"

class chess_board {
public:
    chess_board(int,int);
    ~chess_board(void);
    int ** getBoard(void);
    void move(int row, int col);
    void printBoard();

private:
    int ** _chessboard;
    int _row,_col;
    int _number_of_moves;
    Stack<postion> * postion_stack;
};


#endif //KNIGTHS_TOURS_CHRESSBOARD_H
