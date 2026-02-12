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

void Dig(MinesBoard real,MinesBoard visible,int row,int column,bool gameOver){
    if(real.GetTile(row,column)=='X')
    {
        gameOver=true;
    }
    else if (real.GetTile(row,column)=='0')//there goes all the stuff
    {
        /*
        if (row>0 && column>0 && row<ROWS-1 && column<COLUMNS-1)
        else if (row>0 && column>0 && row<ROWS-1 && column<COLUMNS-1)
        else if (row>0 && column>0 && row<ROWS-1 && column<COLUMNS-1)
        else if (row>0 && column>0 && row<ROWS-1 && column<COLUMNS-1)
        else if (row>0 && column>0 && row<ROWS-1 && column<COLUMNS-1)
        else if (row>0 && column>0 && row<ROWS-1 && column<COLUMNS-1)
        else if (row>0 && column>0 && row<ROWS-1 && column<COLUMNS-1)
        else if (row>0 && column>0 && row<ROWS-1 && column<COLUMNS-1)

        */
    }
    else{
        visible.SetTile(row,column,real.GetTile(row,column));
    }
}