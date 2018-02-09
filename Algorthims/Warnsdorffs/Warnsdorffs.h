//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#ifndef KNIGTHS_TOURS_WARNSDORFFS_H
#define KNIGTHS_TOURS_WARNSDORFFS_H

#include "../../utils/postion/postion.h"
#include "../../chess_board/chess_board.h"

class Warnsdroffs {
public:
    Warnsdroffs(int **);

    void nextMove(chess_board * board);
private:
    int ** arr;
    static const int  N = 8;

    int getDegree( int x, int y);
    bool isempty( int x, int y);
};

#endif //KNIGTHS_TOURS_WARNSDORFFS_H
