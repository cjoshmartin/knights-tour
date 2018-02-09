//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#ifndef KNIGTHS_TOURS_DEPTHFIRST_H
#define KNIGTHS_TOURS_DEPTHFIRST_H


#include "../Algorthims.h"

class DepthFirst: Algorthims {
public:

    DepthFirst(int **arr, chess_board *);

    virtual ~DepthFirst();
    void algorithm(void);
};


#endif //KNIGTHS_TOURS_DEPTHFIRST_H
