#pragma once

#define ROWS 8
#define COLUMNS 8
#include<iostream>
#include<array>

class MinesBoard{
    int number_of_mines=10;
    char tiles[ROWS][COLUMNS];
    // std::array<std::array<char, ROWS>,COLUMNS> tiles;


public:
    MinesBoard();
    void SetBoard();        // board setup before start
    char GetTile(int,int);  // get value of tile at coordinates
    void SetTile(int, int); // set value of tile at coordinates
};