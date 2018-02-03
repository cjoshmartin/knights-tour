#include <iostream>
#include <stdio.h>
#include "chess_board.h"
#include "State.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define Max_Rows 8
#define Max_Cols  8

static int p_moves_row [Max_Rows] = {1,1,2,-2,-1,-1,-2,-2};
static  int p_moves_col[Max_Cols] = {2,-2,1,-1,2,-2,1,-1};

bool can_move(int row, int col, int ** control_board)
{
    return ((col >= 0 && row >=0 ) && (row < Max_Rows && col < Max_Cols) && ( control_board[row][col] < 0 ));
}
int getDegree(int ** control_board, int row, int col)
{
    int count =0;
    for (int i =0; i < Max_Rows; i++)
    {
        if(can_move((row + p_moves_row[i]),(col + p_moves_col[i]),control_board))
            count++;
    }
    return count;
}

bool neighbour(int x, int y, int xx, int yy)
{
    int i=0;
    while(i++ < Max_Rows){
        bool p1 = (x + p_moves_row[i]) == xx, p2 = (y + p_moves_col[i]) == yy,p3 = p1 && p2;
        if (p3 == yy) return true;
    }
    return false;
}

bool next_move(int ** control_b, chess_board * board, int  *row, int *col){

    int min_deg_of_move = -1, c, min_deg_row = (Max_Rows + 1), next_row, next_col;
    int start;
    start = rand() % Max_Rows;
    for (int i = 0; i < Max_Rows; ++i)
    {
        int starting_i = (start + i) % Max_Rows;
         next_row = *row + p_moves_row[starting_i];
         next_col = *col + p_moves_col[starting_i];

        if(can_move(next_row,next_col,control_b) && (c = getDegree(control_b,next_row,next_col)) < min_deg_row)
        {
            min_deg_of_move = starting_i;
            min_deg_row = c;
        }
    }
    if(min_deg_of_move == -1)
        return false;

    next_row = *row + p_moves_row[min_deg_of_move];
    next_col = *col + p_moves_col[min_deg_of_move];

    board->move(next_row,  next_col);

    // TODO update to row and col
    *row = next_row;
    *col = next_col;
    return true;
}
bool tour(int** arr, chess_board * chess, postion current){

    int row =current.row, col = current.col;
    for(int i = 0; i< Max_Cols*Max_Rows-1; ++i)
        if(next_move(arr,chess,&current.row,&current.col) == 0)
            return false;

    if(!neighbour(current.row,current.col, row, col)) // TODO don't understand
        return false;

    return true;
}
int main() {
    srand (time(NULL));

    State * head = new State();
    postion current = head->current_position;

    chess_board * main_board = new chess_board(Max_Rows,Max_Cols);
    int ** control_board = main_board->getBoard();

    std::cout << "||| Enter the initial postion of the knight |||\n";
    std::cout << "||| Enter the row: ";
    std::cin >> current.row;
    std::cout << "||| Enter the column: ";
    std::cin >> current.col;

    main_board->move(current.row,current.col);
//    main_board->printBoard();

    while(!tour(control_board,main_board,current)){}

    std::cout << std::endl;
    return 0;
}