//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include <cstdlib>
#include "Warnsdorffs.h"


Warnsdroffs::Warnsdroffs(int ** arr, chess_board * board_controls) : Algorthims(arr,board_controls){}

int Warnsdroffs::getDegree( int x, int y)
{
    int count = 0;
    for (int i = 0; i < Max_Number_alg; ++i)
        if (this->isEmpty((x + cx[i]), (y + cy[i])))
            count++;
    return count;
}

// Picks next point using Warnsdorff's heuristic.
// Returns false if it is not possible to pick
// next point.
void Warnsdroffs::algorthim() {
    int min_deg_idx = -1, c, min_deg = (Max_Number_alg + 1), nextrow, nextcol;

    // Try all Max_Number_alg adjacent of (*x, *y) starting
    // from a random adjacent. Find the adjacent
    // with minimum degree.
    int start = rand() % Max_Number_alg;

    int row = this->board_controls->current_position().get_row();
    int col = this->board_controls->current_position().get_col();

    for (int count = 0; count < Max_Number_alg; ++count) {
        int i = (start + count) % Max_Number_alg;
        nextrow = row + this->cx[i];
        nextcol = col + this->cy[i];
        if ((this->isEmpty(nextrow, nextcol)) && (c = getDegree(nextrow, nextcol)) < min_deg) {
            min_deg_idx = i;
            min_deg = c;
        }
    }

    // IF we could not find a next cell
    if (min_deg_idx == -1)
        this->board_controls->backtrack();
    else {

        this->board_controls->move(row + this->cx[min_deg_idx], col + this->cy[min_deg_idx],min_deg_idx);
    }

}

