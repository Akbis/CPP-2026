#pragma once

#define WIDTH 20
#define HEIGHT 20

#include<vector>
#include <iostream>
#include<time.h>

enum Direction{RIGHT=1,DOWN,LEFT,UP};
struct Point
{
    int x,y;
    // Point& operator=(Point&);

};

class SnakeBoard{
    char board[WIDTH][HEIGHT];
    Point head={WIDTH/2,HEIGHT/2};
    Point fruit;
    std::vector<Point> tail={{WIDTH/2,HEIGHT/2}}; // Tail, first element of vector is end of the tail

public:
    SnakeBoard();
    void Draw();
    int GetLength();
    Point GetHead();
    std::vector<Point> GetTail();
    void Eat();
    void Move(Direction);

};