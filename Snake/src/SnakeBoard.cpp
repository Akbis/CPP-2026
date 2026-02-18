#include"SnakeBoard.h"

SnakeBoard::SnakeBoard(){
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            board[i][j] = '*';
        }
    }
    board[head.x][head.y] = '@';
     for (size_t i = 1; i < tail.size(); i++)
    {
        board[tail.at(i).x][tail.at(i).y] = '0';
    }
}

void SnakeBoard::Draw(){
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int SnakeBoard::GetLength(){
    return tail.size();
}

Coordinates SnakeBoard::GetHead(){
    return head;
}

std::vector<Coordinates> SnakeBoard::GetTail(){
    return tail;
}