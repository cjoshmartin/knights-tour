//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#ifndef KNIGTHS_TOURS_STATE_H
#define KNIGTHS_TOURS_STATE_H

#include "postion.h"
#include "chess_board.h"

class State {
public:
    State(void);
    State(chess_board);
    ~State(void);

    postion current_position;

private:
    chess_board * current_board;

};


#endif //KNIGTHS_TOURS_STATE_H
