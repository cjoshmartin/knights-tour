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
}

bool Algorthims::isEmpty(int x, int y) {
    return (x >= 0 && y >= 0) && (x < N && y < N) && (arr[x][y] < 0);
}


