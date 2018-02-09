//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#ifndef KNIGTHS_TOURS_POSTION_H
#define KNIGTHS_TOURS_POSTION_H
class postion {
public:
    postion(int row, int col);


    int get_row() const;

    int get_col() const;

    void set_position_index(int _position_index);

    postion * next = nullptr;

private:
    int _row,_col;
    int _position_index;
};
#endif //KNIGTHS_TOURS_POSTION_H
