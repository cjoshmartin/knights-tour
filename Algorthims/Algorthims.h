//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#ifndef KNIGTHS_TOURS_ALGORTHIMS_H
#define KNIGTHS_TOURS_ALGORTHIMS_H


#include "../chess_board/chess_board.h"

class Algorthims {
public:

    Algorthims(int **arr,chess_board * board_contols );

protected:

    int ** arr;
    chess_board * board_controls;
    static const int  N = 8;

    static int cx[8] = {1,1,2,2,-1,-1,-2,-2};
    static int cy[8] = {2,-2,1,-1,2,-2,1,-1};

    bool isEmpty(int x, int y);
};


#endif //KNIGTHS_TOURS_ALGORTHIMS_H
