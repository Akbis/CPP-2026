#pragma once

#define ROWS 8
#define COLUMNS 8

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<vector>
#include<algorithm>
#include<numeric>

class MinesBoard{
    int uncovered_tiles=0;
    int number_of_mines=10;
    char tiles[ROWS][COLUMNS];
    char shownTiles[ROWS][COLUMNS];



public:
    MinesBoard();                           // fills the board with '*'
    void SetBoard();                        // board setup before start
    char GetTile(int,int);                  // get value of tile at coordinates
    void SetTile(int, int, char);           // set value of tile at coordinates
    char GetShownTile(int, int);            // get value of tile at coordinates
    void SetShownTile(int, int, char);      // set value of tile at coordinates
    char CountSurroundingMines(int,int);    // calculates number of mines in 8 surrounding tiles. NOTE: beware of edge cases and corner cases
    void Dig(int, int);                // discovers tile on if it equals '0' also surrounding tiles
    bool IsGameWon();
};

/* Two Board Implementation:
if remaking this using TBI, use pointers to Boards, also using pointers to tiles will get rid of most of Dig() and CountSurroundingMines() functions
*/