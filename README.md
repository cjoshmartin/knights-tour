# knights-tour

## Problem
 You are on a chess board, with only a Knight chess piece. Your Queen is trapped in a secret castle, and the only way to save her is by **visiting every square on the board, once without repeating**.

 ## A video solution

 [Click here, if you dare?!?](https://youtu.be/ab_dY3dZFHM?t=58s)

## Grading of Assigment
1) correctness of program
2) organization of program
3) readability of the program
4) the report

 ## Paper on Assigment
**MUST BE 5 PRINTED PAGES IN LENGTH**
1)  The project description (in your words)
2)   any other comments and conclusions that you may prefer to include. The report, **excluding the source code and outputs**


 ## Requirements
 #### Two Overall Components

1. Implementation of a singly linked list (with associated operations) to store the user inputs concerning the initial positions of the knight.
2. Solving the knight’s tour problem for each initial position using a stack, backtracking, andusing Warnsdoff’s heuristic for the first 32 moves.

The two components should work together. All the messages, and/or the transcript of a session demonstrating the successful operation of the complete program, **should be saved in the output file**.

 #### General
 * The board is an 8×8 array of integers, all elements of the array are initially set at −1.
 * As you move to a square, you replace the corresponding array element by the sequence number of the move made (such as 1 for the square visited after the first move, 2 for the second move).
 *  At **each instant the board state** with any other necessary information is **pushed on to the stack**.

    * This is to recover from the case when the knight is trapped somewhere, with no unvisited square to move to, without finding the complete solution.
* If, at a particular instant, the knight’s position on the board is given by (i,j), there may be at most eight possible moves for the knight which will move it to one of the squares (i − 2,j + 1),(i−1,j +2),(i+1,j +2),(i+2,j +1),(i+2,j −1),(i+1,j −2),(i−1,j −2),(i−2,j −1).
* choose moves using Warndoff’s heuristic for the first 32 (out of the total of 63 moves in the solution, then you turn off the heuristics, and choose moves in an exhaustive manner. This will require the use of some back-tracking (and, hence, a stack)
#### Data entry mode
* The project also requires the use of a singly linked list to store a number of choices of initial conditions for the knight
* Before solving the problem for any initial condition, the program should prompt the user incrementally to enter the initial conditions, but should not ask for the number of initial positions that the user wishes to enter.
* At the end of this data entry mode, the program should display all the positions entered. It should then further prompt to see if the user wants to add, delete, or modify the list of initial positions.

#### Initial Position
* For each initial position, the program would then solve the knight’s tour problem.
