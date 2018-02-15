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
    int tx[8] = {1,1,2,2,-1,-1,-2,-2};
    int ty[8] = {2,-2,1,-1,2,-2,1,-1};

    for (int i = 0; i < 8 ; ++i) {
        this->cx[i]= tx[i];
        this->cy[i] = ty[i];
    }
}

bool Algorthims::isEmpty(int x, int y) {
    return (x >= 0 && y >= 0) && (x < Max_Number_alg && y < Max_Number_alg) && (arr[x][y] < 0);
}

Algorthims::~Algorthims() {
    delete[] cy;
    delete[] cx;
}



