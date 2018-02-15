//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include <stdexcept>
#include "postion.h"

postion::postion(int _row, int _col) : _row(_row), _col(_col), _position_index(-1) /* -1 because I can check if it has visited a point*/{}

int postion::get_row() const {
    return _row;
}

int postion::get_col() const {
    return _col;
}

void postion::set_position_index(int position_index) {

    if (position_index  < 0)
        throw  std::invalid_argument("Invalid attempt set position index");

    _position_index = position_index;
}

int postion::get_position_index() const {
    return _position_index;
}

postion::~postion() {

    delete next;
}
