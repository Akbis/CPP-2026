#pragma once

#define WIDTH 5
#define HEIGHT 5

#include<vector>
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
    char board[HEIGHT+2][WIDTH];
    Point head={WIDTH/2,HEIGHT/2};
    Point fruit;
    std::vector<Point> tail = {{WIDTH / 2 - 3, HEIGHT / 2}, {WIDTH / 2 - 2, HEIGHT / 2}, {WIDTH / 2 - 1, HEIGHT / 2}}; // Tail, first element of vector is end of the tail
    Direction defaultDirection = RIGHT;

public:
    SnakeBoard();                       // Board initialization
    int Score();                        // Returns score
    void SyncBoard();                   // Updates snake position on the board
    void Move(Direction);               // Moving head and tail also checking for fruit and board edges
    bool IsGameLost();                  // Checks for defeat conditions
    void PlaceFruit();                  // may or may not be used 
    Direction GetDefaultDirection();    // current direction of movement used when no input 

    char GetTile(int,int);              // returns tile at given coordinates

};

Direction OppositeDirection(Direction dir);

// here snake and the board are in a way completly independent entities, have to remember that changing head or tail doesnt impact the board

