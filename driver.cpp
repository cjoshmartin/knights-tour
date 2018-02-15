#include <iostream>
#include <stdio.h>
#include "chess_board/chess_board.h"
#include "Algorthims/Warnsdorffs/Warnsdorffs.h"
#include "Algorthims/DepthFirst/DepthFirst.h"

#define  n 8
#define LINE "-----------------------------------------------------------------------------------------------"

/// (4,1)
void first_move( chess_board * board_controls,bool debug){
    int row =0, col =0;

    if(!debug) {
        char anws ='y';
        bool cant_go_to;
        do {
            cant_go_to = false;
            std::cout << "\n" << LINE << "\n";
           std::cout << board_controls->printBoard(false)<< "\n\tNOTE: -1 means you can move to that position. \n\n";

            std::cout << "||| Enter the initial position of the knight |||\n";
            std::cout << "||| Enter the row: ";
            std::cin >> row;
            while(std::cin.fail() || row > n || row < 0)
            {
                std::cout << "Sorry the ROW you have tried to enter is not valid, please try again: ";

               if (std::cin.fail())
               {
                   std::cin.clear();
                   std::cin.ignore(256,'\n');
               }
                std::cin >> row;
            }
            std::cout << "||| Enter the column: ";
            std::cin >> col;

            while(std::cin.fail() || col > n || col < 0)
            {
                std::cout << "Sorry the COL you have tried to enter is not valid, please try again: ";

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                }
                std::cin >> col;
            }

            if(!board_controls->is_vaild_move(row,col))
            {
                std::cout << "\nSorry your input for ROW And COL is unvalid, please try again.\n";
                cant_go_to = true;
            }
            else {
                std::cout << "\ncurrent move:\n";
                board_controls->move(col, row, 0);

                std::cout << "\nList of all moves:\n";
                board_controls->printToScreen();
                if(board_controls->number_of_moves() > 1)
                {
                    char to_delete;

                    std::cout << "\nWould you like to DELETE the last move (y/n) : ";
                    std::cin >> to_delete;
                    while(std::cin.fail() ||(to_delete != 'y' && to_delete != 'n'))
                    {
                        std::cout << "Sorry the input you have tried to enter is not valid, please try again: ";

                        if (std::cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(256,'\n');
                        }
                        std::cin >> to_delete;
                    }

                    std::cout << std::endl;

                    if(to_delete =='y')
                        board_controls->backtrack();
                }
                std::cout << "\nWould you like to keep going? (y/n): ";
                std::cin >> anws;
                std::cout << std::endl;
                while (anws != 'y' && anws != 'n') {
                    std::cout << "Sorry your input was unvalid, please try again (y/n): ";
                    std::cin >> anws;
                    std::cout << std::endl;
                }
            }
        }while (anws == 'y' || cant_go_to);
    }
    else
    {
        row = rand() % n;
        col = rand() % n;
        board_controls->move(row,col,-1);
    }
}


// Driver code
int main()
{
    bool debug = true; // TODO

    chess_board * board_controls =     new chess_board(n,n);

    Warnsdroffs * warnsdroff     =     new Warnsdroffs(board_controls->getBoard(),board_controls);
//    DepthFirst  * depthfirst     =     new DepthFirst(board_controls->getBoard(),board_controls);

    first_move(board_controls,debug);
/*
do { */
    //while (board_controls->number_of_moves() < 32)
      warnsdroff->algorthim();

/*    while(board_controls->number_of_moves() >= 32 & board_controls->number_of_moves() < 64)
       depthfirst->algorthim();

}while (board_controls->number_of_moves() < 64);
*/
   // board_controls->printBoard(true);
   // board_controls->printSuccessfulPath(true);
   // board_controls->printToScreen();
   // board_controls->printToFile("OUTPUT_of_tour.txt");

    delete warnsdroff;
    delete board_controls;
    return 0;
}
