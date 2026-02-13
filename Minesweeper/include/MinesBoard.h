#pragma once

#define ROWS 16
#define COLUMNS 16

#include <iostream>
#include<cstdlib>
#include<time.h>
#include<vector>
#include<algorithm>
#include<numeric>

class MinesBoard{
    int number_of_mines=10;
    char tiles[ROWS][COLUMNS];
    char shownTiles[ROWS][COLUMNS];
    // std::array<std::array<char, ROWS>,COLUMNS> tiles;


public:
    MinesBoard();                       // fills the board with '*'
    void SetBoard();                    // board setup before start
    char GetTile(int,int);              // get value of tile at coordinates
    void SetTile(int, int, char);       // set value of tile at coordinates
    char GetShownTile(int, int);             // get value of tile at coordinates
    void SetShownTile(int, int, char);       // set value of tile at coordinates
    char CountSurroundingMines(int,int); // calculates number of mines in 8 surrounding tiles. NOTE: beware of edge cases and corner cases
    void Dig(int, int,bool);             // discovers tile on if it equals '0' also surrounding tiles
};

