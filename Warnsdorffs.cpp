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


static int cx[8] = {1,1,2,2,-1,-1,-2,-2};
static int cy[8] = {2,-2,1,-1,2,-2,1,-1};


Warnsdroffs::Warnsdroffs(int * array): arr(array){}
// Move pattern on basis of the change of
// x coordinates and y coordinates respectively

// function restricts the knight to remain within
// the 8x8 chessboard
bool Warnsdroffs::limits(int x, int y)
{
    return ((x >= 0 && y >= 0) && (x < N && y < N));
}

/* Checks whether a square is valid and empty or not */
bool Warnsdroffs::isempty( int x, int y)
{
    return (limits(x, y)) && (arr[y*N+x] < 0);
}

/* Returns the number of empty squares adjacent
   to (x, y) */
int Warnsdroffs::getDegree( int x, int y)
{
    int count = 0;
    for (int i = 0; i < this->N; ++i)
        if (isempty((x + cx[i]), (y + cy[i])))
            count++;
//    std::cout << "number of adjacent: " << count << std::endl;
    return count;
}

// Picks next point using Warnsdorff's heuristic.
// Returns false if it is not possible to pick
// next point.
bool Warnsdroffs::nextMove( int *x, int *y)
{
    int min_deg_idx = -1, c, min_deg = (N+1), nx, ny;

    // Try all N adjacent of (*x, *y) starting
    // from a random adjacent. Find the adjacent
    // with minimum degree.
    int start = rand()%N;
    for (int count = 0; count < N; ++count)
    {
        int i = (start + count)%N;
        nx = *x + cx[i];
        ny = *y + cy[i];
        if ((isempty(nx, ny)) &&
            (c = getDegree(nx, ny)) < min_deg)
        {
            min_deg_idx = i;
            min_deg = c;
        }
    }

    // IF we could not find a next cell
    if (min_deg_idx == -1)
        return false;

    // Store coordinates of next point
    nx = *x + cx[min_deg_idx];
    ny = *y + cy[min_deg_idx];

    // Mark next move
    arr[ny*N + nx] = arr[(*y)*N + (*x)]+1;

    // Update next point
    *x = nx;
    *y = ny;

    return true;
}

/* displays the chessboard with all the
  legal knight's moves */
void Warnsdroffs::print()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            printf("%d\t",arr[j*N+i]);
        printf("\n");
    }
}


