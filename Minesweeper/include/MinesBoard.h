#pragma once

#define ROWS 8
#define COLUMNS 8

#include <iostream>
#include<cstdlib>
#include<time.h>
#include<vector>
#include<algorithm>
#include<numeric>

class MinesBoard{
    int number_of_mines=10;
    char tiles[ROWS][COLUMNS];
    // std::array<std::array<char, ROWS>,COLUMNS> tiles;


public:
    MinesBoard();                       // fills the board with '*'
    void SetBoard();                    // board setup before start
    char GetTile(int,int);              // get value of tile at coordinates
    void SetTile(int, int, char);       // set value of tile at coordinates
    char CountSurroundingMines(int,int); // calculates number of mines in 8 surrounding tiles. NOTE: beware of edge cases and corner cases
};

// IDEA: do all the setup for the board, then create another board on top of it which will be used for display.
void Dig(MinesBoard real, MinesBoard visible, int row, int column, bool gameOver);
    // void Dig(MinesBoard real,MinesBoard visible,int row,int column,bool gameOver){
    //     if(real.GetTile(row,column)=='X')
    //     {
    //         gameOver=true;
    //     }
    //     else if (real.GetTile(row,column)=='0')//there goes all the stuff
    //     {
    //         visible.SetTile(row,column,0);
    //         if (row>0 && column>0 && row<ROWS-1 && column<COLUMNS-1){ // here we go again
    //             Dig(real, visible, row-1, column-1, gameOver);
    //             Dig(real, visible, row-1, column, gameOver);
    //             Dig(real, visible, row-1, column+1, gameOver);
    //             Dig(real, visible, row, column-1, gameOver);
    //             Dig(real, visible, row, column+1, gameOver);
    //             Dig(real, visible, row+1, column-1, gameOver);
    //             Dig(real, visible, row+1, column, gameOver);
    //             Dig(real, visible, row+1, column+1, gameOver);
    //         }
    //         else if (row==0 && column>0 && column<COLUMNS-1){ //edge case 1
    //             Dig(real, visible, row, column-1, gameOver);
    //             Dig(real, visible, row, column+1, gameOver);
    //             Dig(real, visible, row+1, column-1, gameOver);
    //             Dig(real, visible, row+1, column, gameOver);
    //             Dig(real, visible, row+1, column+1, gameOver);
    //         }
    //         else if (row==ROWS-1 && column>0 && column<COLUMNS-1){ //edge case 2
    //             Dig(real, visible, row-1, column-1, gameOver);
    //             Dig(real, visible, row-1, column, gameOver);
    //             Dig(real, visible, row-1, column+1, gameOver);
    //             Dig(real, visible, row, column-1, gameOver);
    //             Dig(real, visible, row, column+1, gameOver);
    //         }
    //         else if (column==0 && row>0 && row<ROWS-1){ //edge case 3
    //             Dig(real, visible, row-1, column+1, gameOver);
    //             Dig(real, visible, row, column+1, gameOver);
    //             Dig(real, visible, row+1, column+1, gameOver);
    //             Dig(real, visible, row-1, column, gameOver);
    //             Dig(real, visible, row+1, column, gameOver);
    //         }
    //         else if (column==COLUMNS-1 && row>0 && row<ROWS-1){ //edge case 4
    //             Dig(real, visible, row-1, column-1, gameOver);
    //             Dig(real, visible, row, column-1, gameOver);
    //             Dig(real, visible, row+1, column-1, gameOver);
    //             Dig(real, visible, row-1, column, gameOver);
    //             Dig(real, visible, row+1, column, gameOver);
    //         }
    //         else if (row==0 && column==0){ //corner case 1
    //             Dig(real, visible, row, column+1, gameOver);
    //             Dig(real, visible, row+1, column, gameOver);
    //             Dig(real, visible, row+1, column+1, gameOver);
    //         }
    //         else if (row==ROWS-1 && column==0){ //corner case 2
    //             Dig(real, visible, row-1, column, gameOver);
    //             Dig(real, visible, row-1, column+1, gameOver);
    //             Dig(real, visible, row, column+1, gameOver);
    //         }
    //         else if (row==0 && column==COLUMNS-1){ //corner case 3
    //             Dig(real, visible, row, column-1, gameOver);
    //             Dig(real, visible, row+1, column-1, gameOver);
    //             Dig(real, visible, row+1, column, gameOver);
    //         }
    //         else if (row==ROWS-1 && column==COLUMNS-1){ //corner case 4
    //             Dig(real, visible, row-1, column, gameOver);
    //             Dig(real, visible, row-1, column-1, gameOver);
    //             Dig(real, visible, row, column-1, gameOver);
    //         }
    //         else // Should not be necessary, but just in case
    //             std::cout << "Error. Now check all the ifs, this time in Dig()";
    //     }
    //     else{
    //         visible.SetTile(row,column,real.GetTile(row,column));
    //     }
    // }