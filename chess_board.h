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


class chess_board {
public:
    chess_board(int,int);
    ~chess_board(void);
    int ** getBoard();
    void printBoard();

private:
    int ** _chessboard;
    int _row,_col;
};


#endif //KNIGTHS_TOURS_CHRESSBOARD_H
