
#include <cstdlib>
#include "Warnsdorffs.h"


Warnsdroffs::Warnsdroffs(int ** arr, chess_board * board_controls) : Algorthims(arr,board_controls){}


void Warnsdroffs::algorthim() {
    int min_deg, nextrow, nextcol;
    min_deg = (Max_Number_alg + 1);
    int c;
    int min_deg_idx = -1;

    int start = rand() % Max_Number_alg;

    // TODO

//    int row = this->board_controls->current_position().get_row();
//    int col = this->board_controls->current_position().get_col();
 int row =0;
    int col =0;
    for (int count = 0; count < Max_Number_alg; ++count) {
        int i = (start + count) % Max_Number_alg;
        nextrow = row + this->cx[i];
        nextcol = col + this->cy[i];
        if ((this->isEmpty(nextrow, nextcol)) && (c = getDegree(nextrow, nextcol)) < min_deg) {
            min_deg_idx = i;
            min_deg = c;
        }
    }

    if (min_deg_idx == -1)
        this->board_controls->backtrack();
    
    else {
        int next_row =row + this->cx[min_deg_idx];
        int next_col = col + this->cy[min_deg_idx]; 
        this->board_controls->move(next_row,next_col ,min_deg_idx);
    }

}

int Warnsdroffs::getDegree( int x, int y)
{
    int count = 0;
    for (int i = 0; i < Max_Number_alg; ++i)
        if (this->isEmpty((x + cx[i]), (y + cy[i])))
            count++;
    return count;
}

Warnsdroffs::~Warnsdroffs() {

}
