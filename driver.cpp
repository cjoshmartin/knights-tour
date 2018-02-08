#include <iostream>
#include <stdio.h>
#include "chess_board.h"
#include "State.h"
#include "Warnsdorffs.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// Driver code
int main()
{
    bool debug = true;
    // To make sure that different random
    // initial positions are picked.
    srand(time(NULL));
    State * head = new State();
    int tacos[8];
    Warnsdroffs * warnsdroff =  new Warnsdroffs(tacos);
    postion * current = &head->current_position;

    if(!debug) {
        std::cout << "||| Enter the initial position of the knight |||\n";
        std::cout << "||| Enter the row: ";
        std::cin >> current->row;
        std::cout << "||| Enter the column: ";
        std::cin >> current->col;
    }
    if (debug){ current->row= 0; current->col = 0;}


    // While we don't get a solution
    while (warnsdroff->findClosedTour(current))
    {
        ;
    }

    return 0;
}
