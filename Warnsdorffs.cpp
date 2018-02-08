//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "Warnsdorffs.h"
#include "chess_board.h"


static int cx[8] = {1,1,2,2,-1,-1,-2,-2};
static int cy[8] = {2,-2,1,-1,2,-2,1,-1};


Warnsdroffs::Warnsdroffs(int ** array): arr(array){}

/* Checks whether a square is valid and empty or not */
bool Warnsdroffs::isempty( int x, int y)
{
    return (x >= 0 && y >= 0) && (x < N && y < N) && (arr[x][y] < 0);
}

/* Returns the number of empty squares adjacent
   to (x, y) */
int Warnsdroffs::getDegree( int x, int y)
{
    int count = 0;
    for (int i = 0; i < N; ++i)
        if (isempty((x + cx[i]), (y + cy[i])))
            count++;
    return count;
}

// Picks next point using Warnsdorff's heuristic.
// Returns false if it is not possible to pick
// next point.
void Warnsdroffs::nextMove(chess_board * board) {
    int min_deg_idx = -1, c, min_deg = (N + 1), nx, ny;

    // Try all N adjacent of (*x, *y) starting
    // from a random adjacent. Find the adjacent
    // with minimum degree.
    int start = rand() % N;

    int x = board->current_position().get_row();
    int y = board->current_position().get_col();

    for (int count = 0; count < N; ++count) {
        int i = (start + count) % N;
        nx = x + cx[i];
        ny = y + cy[i];
        if ((isempty(nx, ny)) &&
            (c = getDegree(nx, ny)) < min_deg) {
            min_deg_idx = i;
            min_deg = c;
        }
    }

    // IF we could not find a next cell
    if (min_deg_idx == -1)
        board->backtrack();
    else {

        // Store coordinates of next point
        nx = x + cx[min_deg_idx];
        ny = y + cy[min_deg_idx];

        // Update next point
        board->move(nx, ny);
    }

}