//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include "Algorthims.h"

Algorthims::Algorthims(int **arr, chess_board * board_contols) : arr(arr), board_controls(board_contols){

    // cannot have static const in a class ????
    int possible_row_filler[8] = {1,1,2,2,-1,-1,-2,-2};
    int possible_cols_filler[8] = {2,-2,1,-1,2,-2,1,-1};

    // if you have a better way of doing this please let me know
    for (int i = 0; i < 8 ; ++i) {
        this->possible_rows[i]= possible_row_filler[i];
        this->possible_cols[i] = possible_cols_filler[i];
    }
}

bool Algorthims::isEmpty(int row, int col) {
    return (row >= 0 && col >= 0) && (row < Max_Number_alg && col < Max_Number_alg) && (arr[row][col] < 0);
}

Algorthims::~Algorthims() {
}



