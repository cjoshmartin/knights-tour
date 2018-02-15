
#include <cstdlib>
#include "Warnsdorffs.h"


Warnsdroffs::Warnsdroffs(int ** arr, chess_board * board_controls) : Algorthims(arr,board_controls){}


void Warnsdroffs::algorthim() {
    int smallest_degree_possible_moves;

    smallest_degree_possible_moves = Max_Number_alg;
    smallest_degree_possible_moves++;
    int check;
    int smallest_degree_of_row = -1;

    int beginning = rand() % Max_Number_alg;


    int row = this->board_controls->current_position().get_row();
    int col = this->board_controls->current_position().get_col();

    for (int i = 0; i < Max_Number_alg; ++i) {

        int postion = i;
        postion += beginning;
        int random_postion = postion % Max_Number_alg;

       int nextrow = row + this->possible_rows[random_postion];
       int nextcol = col + this->possible_cols[random_postion];

        if (this->isEmpty(nextrow, nextcol)) {
            if ((check = getDegree(nextrow, nextcol, 0, 0)) < smallest_degree_possible_moves) {
                smallest_degree_possible_moves = check;
                smallest_degree_of_row = random_postion;
            }
        }
    }

    if (smallest_degree_of_row == -1)
        this->board_controls->backtrack();
    
    else {
        int next_row =row + this->possible_rows[smallest_degree_of_row];
        int next_col = col + this->possible_cols[smallest_degree_of_row];
        this->board_controls->move(next_row,next_col ,smallest_degree_of_row);
    }

}

Warnsdroffs::~Warnsdroffs() {

}

int Warnsdroffs::getDegree(int row, int col, int i, int number_of_degree) {

    if(i < Max_Number_alg)
    {
        int testrow = row + possible_rows[i];
        int testcol = col + possible_cols[i];

        if (this->isEmpty(testrow,testcol))
            return getDegree(row,col,i+1,number_of_degree+1);

        return getDegree(row,col,i+1,number_of_degree);
    }

    return number_of_degree;
}
