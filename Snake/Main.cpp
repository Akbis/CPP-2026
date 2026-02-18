#define WIDTH 20
#define HEIGHT 20
// #include"SnakeBoard.h"
#include<iostream>
#include<curses.h>
#include<vector>

void Draw(char Board[WIDTH][HEIGHT]);
void SetUp(char Board[WIDTH][HEIGHT], int xHead, int yHead, std::vector<int> xTail, std::vector<int> yTail);

    int main()
{
    char Board[WIDTH][HEIGHT];
    int xHead=WIDTH/2, yHead=HEIGHT/2;
    std::vector<int> xTail={xHead},yTail={yHead};
    SetUp(Board, xHead, yHead, xTail, yTail);
    Draw(Board);
}

void Draw(char Board[WIDTH][HEIGHT]){
    for(int i=0;i<WIDTH;i++){
        for (int j= 0; j < HEIGHT; j++)
        {
            std::cout<<Board[i][j]<<" ";
        }       
        std::cout<<"\n";
    }
}

void SetUp(char Board[WIDTH][HEIGHT], int xHead, int yHead, std::vector<int> xTail, std::vector<int> yTail)
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            Board[i][j]='*';
        }
    }
    Board[xHead][yHead]='@';
    for(size_t i=1;i<xTail.size();i++){
        Board[xTail.at(i)][yTail.at(i)]='0';
    }
}