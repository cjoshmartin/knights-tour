//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include "postion.h"

postion::postion(int _row, int _col) : _row(_row), _col(_col) {}

int postion::get_row() const {
    return _row;
}

int postion::get_col() const {
    return _col;
}
