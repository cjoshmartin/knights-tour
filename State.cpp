//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include "State.h"

State::State(void) {

}

State::State(chess_board  copyboard) {
    current_board = &copyboard;
}

State::~State(void) {

}
