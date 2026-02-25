#pragma once

#define WIDTH 5
#define HEIGHT 5

#include<vector>
#include <iostream>
#include<time.h>
#include<algorithm>
#include<numeric>

enum Direction{RIGHT=1,DOWN,LEFT,UP};
struct Point
{
    int x,y;
    bool operator==(Point&);
};

class SnakeBoard{
    char board[WIDTH][HEIGHT];
    Point head={WIDTH/2,HEIGHT/2};
    Point fruit;
    int lenght=2;   // probably useless, though might rename it to score
    std::vector<Point> tail = {{WIDTH / 2 - 1, HEIGHT / 2}}; // Tail, first element of vector is end of the tail
    Direction defaultDirection=RIGHT;

public:
    SnakeBoard();                   // Board initialization
    void Draw();                    // Draws the board
    int GetLength();                // Returns tail lenght          //maybe useless
    Point GetHead();                // Returns coordinates of head  //maybe useless
    std::vector<Point> GetTail();   // Returns tail                 //maybe useless
    void SyncBoard();               // Updates snake position on the board
    void Eat();                     // Logic when location of head == location of fruit
    void Move(Direction);           // Moving head and tail also checking for fruit and board edges
    bool IsGameLost();              // Checks for defeat conditions
    void PlaceFruit();              // may or may not be used 
    Direction GetDefaultDirection();     // current direction of movement used when no input 

};

Direction OppositeDirection(Direction dir);

// here snake and the board are in a way completly independent entities, have to remember that changing head or tail doesnt impact the board

// Will have to add tracking of current direction to prevent 180 turns