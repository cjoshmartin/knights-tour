// C++ program to for Kinight's tour problem usin
// Warnsdorff's algorithm
#include <iostream>
#include <stdio.h>
#include "chess_board.h"
#include "State.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define N 8

// Move pattern on basis of the change of
// x coordinates and y coordinates respectively
static int cx[N] = {1,1,2,2,-1,-1,-2,-2};
static int cy[N] = {2,-2,1,-1,2,-2,1,-1};

// function restricts the knight to remain within
// the 8x8 chessboard
bool limits(int x, int y)
{
    return ((x >= 0 && y >= 0) && (x < N && y < N));
}

/* Checks whether a square is valid and empty or not */
bool isempty(int a[N][N], int x, int y)
{
    return (limits(x, y)) && (a[x][y] < 0);
}

/* Returns the number of empty squares adjacent
   to (x, y) */
int getDegree(int a[N][N], int x, int y)
{
    int count = 0;
    for (int i = 0; i < N; ++i)
        if (isempty(a, (x + cx[i]), (y + cy[i])))
            count++;

    return count;
}

// Picks next point using Warnsdorff's heuristic.
// Returns false if it is not possible to pick
// next point.
bool nextMove(int a[N][N], int *x, int *y)
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
        if ((isempty(a, nx, ny)) &&
            (c = getDegree(a, nx, ny)) < min_deg)
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
//    a[ny*N + nx] = a[(*y)*N + (*x)]+1;
    a[nx][ny] = a[(*x)][(*y)];

    // Update next point
    *x = nx;
    *y = ny;

    return true;
}

/* displays the chessboard with all the
  legal knight's moves */
void print(int a[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
}

/* checks its neighbouring sqaures */
/* If the knight ends on a square that is one
   knight's move from the beginning square,
   then tour is closed */
bool neighbour(int x, int y, int xx, int yy)
{
    for (int i = 0; i < N; ++i)
        if (((x+cx[i]) == xx)&&((y + cy[i]) == yy))
            return true;

    return false;
}

/* Generates the legal moves using warnsdorff's
  heuristics. Returns false if not possible */
bool findClosedTour(int row, int col)
{
    // Filling up the chessboard matrix with -1's
    int a[N][N];
    for (int i = 0; i< N; ++i)
        for (int j = 0; j < N; ++j)
        a[i][j] = -1;

    // Randome initial position
    int sx = row;
    int sy = col;

    // Current points are same as initial points
    int x = sx, y = sy;
    a[x][y] = 1; // Mark first move.

    // Keep picking next points using
    // Warnsdorff's heuristic
    for (int i = 0; i < N*N-1; ++i)
        if (nextMove(a, &x, &y) == 0)
            return false;

    // Check if tour is closed (Can end
    // at starting point)
    if (!neighbour(x, y, sx, sy))
        return false;

    print(a);
    return true;
}

// Driver code
int main()
{
    // To make sure that different random
    // initial positions are picked.
    srand(time(NULL));
    State * head = new State();
    postion current = head->current_position;

    std::cout << "||| Enter the initial postion of the knight |||\n";
    std::cout << "||| Enter the row: ";
    std::cin >> current.row;
    std::cout << "||| Enter the column: ";
    std::cin >> current.col;


    // While we don't get a solution
    while (!findClosedTour(current.row,current.col))
    {
        ;
    }

    return 0;
}
