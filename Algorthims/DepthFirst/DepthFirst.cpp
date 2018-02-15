//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include "DepthFirst.h"


DepthFirst::DepthFirst(int ** arr,chess_board * board_controls):Algorthims(arr,board_controls) {}

DepthFirst::~DepthFirst() {
}

void DepthFirst::algorthim(void) {

    int row = this->board_controls->current_position().get_row();
    int col = this->board_controls->current_position().get_col();

    int i =0, next_index = -1;

    postion current = board_controls->current_position();

    bool should_look =true;

    if (current.get_position_index() > -1)
        i=current.get_position_index() + 1 ;

    if (i > 8)
    should_look =false; // set to false if (position index + 1) > 8, so that
                        // it will not try to find more solutions and will
                        // instead backtrack

    while(i++ < this->Max_Number_alg && next_index == -1 && should_look) {
        int nextrow = row + this->possible_rows[i];
        int nextcol = col + this->possible_cols[i];

        if(this->isEmpty(nextrow,nextcol))
            next_index = i;
    }

    if (next_index == -1)
        board_controls->backtrack();
    else
    {
        board_controls->move(row + this->possible_rows[next_index],col + this->possible_cols[next_index],next_index);
    }

}


