#pragma once

#define WIDTH 20
#define HEIGHT 20

#include<vector>
#include <iostream>
#include<time.h>
struct Point
{
    int x,y;
};

class SnakeBoard{
    char board[WIDTH][HEIGHT];
    Point head={WIDTH/2,HEIGHT/2};
    Point fruit;
    std::vector<Point> tail={{WIDTH/2,HEIGHT/2}};

public:
    SnakeBoard();
    void Draw();
    int GetLength();
    Point GetHead();
    std::vector<Point> GetTail();

};