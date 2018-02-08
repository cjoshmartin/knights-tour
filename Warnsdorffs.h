//
// Honor Pledge:
//
// I pledge that I have neither given nor
//  received any help on this assignment.
//
//chajmart

//

#ifndef KNIGTHS_TOURS_WARNSDORFFS_H
#define KNIGTHS_TOURS_WARNSDORFFS_H

#include "postion.h"

class Warnsdroffs {
public:
    Warnsdroffs(int *);
    bool findClosedTour(postion *current);

private:
    int * arr;
    static const int  N = 8;


    int getDegree(int a[], int x, int y);
    void print(int a[]);
    bool nextMove(int a[], int *x, int *y);
    bool isempty(int a[], int x, int y);
    bool limits(int x, int y);
};

#endif //KNIGTHS_TOURS_WARNSDORFFS_H
