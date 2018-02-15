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

    virtual ~Algorthims();

    virtual void algorthim(void)=0;
protected:

    int ** arr;
    chess_board * board_controls;
    static const int  Max_Number_alg = 8;

    int cx[8];
    int cy[8];

    bool isEmpty(int x, int y);
};


#endif //KNIGTHS_TOURS_ALGORTHIMS_H
