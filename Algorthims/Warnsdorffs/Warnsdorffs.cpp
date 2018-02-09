//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include <cstdlib>
#include <altivec.h>
#include "Warnsdorffs.h"


Warnsdroffs::Warnsdroffs(int ** arr, chess_board * board_controls) : Algorthims(arr,board_controls){}

int Warnsdroffs::getDegree( int x, int y)
{
    int count = 0;
    for (int i = 0; i < N; ++i)
        if (this->isEmpty((x + cx[i]), (y + cy[i])))
            count++;
    return count;
}

// Picks next point using Warnsdorff's heuristic.
// Returns false if it is not possible to pick
// next point.
void Warnsdroffs::nextMove() {
    int min_deg_idx = -1, c, min_deg = (N + 1), nx, ny;

    // Try all N adjacent of (*x, *y) starting
    // from a random adjacent. Find the adjacent
    // with minimum degree.
    int start = rand() % N;

    int x = this->board_controls->current_position().get_row();
    int y = this->board_controls->current_position().get_col();

    for (int count = 0; count < N; ++count) {
        int i = (start + count) % N;
        nx = x + this->cx[i];
        ny = y + this->cy[i];
        if ((this->isEmpty(nx, ny)) && (c = getDegree(nx, ny)) < min_deg) {
            min_deg_idx = i;
            min_deg = c;
        }
    }

    // IF we could not find a next cell
    if (min_deg_idx == -1)
        this->board_controls->backtrack();
    else {

        this->board_controls->move(x + this->cx[min_deg_idx], y + this->cy[min_deg_idx],min_deg_idx);
    }

}

