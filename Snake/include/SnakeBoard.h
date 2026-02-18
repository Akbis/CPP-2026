#pragma once

#define WIDTH 20
#define HEIGHT 20

#include<vector>
#include <iostream>
struct Coordinates
{
    int x,y;
};

class SnakeBoard{
    char board[WIDTH][HEIGHT];
    Coordinates head={WIDTH/2,HEIGHT/2};
    std::vector<Coordinates> tail={{WIDTH/2,HEIGHT/2}};

public:
    SnakeBoard();
    void Draw();
    int GetLength();
    Coordinates GetHead();
    std::vector<Coordinates> GetTail();

};