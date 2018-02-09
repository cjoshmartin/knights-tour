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
#include "../Algorthims.h"

class Warnsdroffs : Algorthims {
public:
    Warnsdroffs(int **, chess_board *);

    void algorthim();
private:

    int getDegree( int x, int y);
};

#endif //KNIGTHS_TOURS_WARNSDORFFS_H
