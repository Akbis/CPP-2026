#include"SnakeBoard.h"


SnakeBoard::SnakeBoard(){
    Point tmpFruit={rand()%WIDTH,rand()%HEIGHT};
    while((tmpFruit.x==head.x && tmpFruit.y==head.y)){
        tmpFruit = {rand() % WIDTH, rand() % HEIGHT};
    }
    fruit=tmpFruit;
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = '*';
        }
    }
    board[head.y][head.x] = '@';
    board[fruit.y][fruit.x] = 'T';
    for (size_t i = 1; i < tail.size(); i++)
    {
        board[tail.at(i).y][tail.at(i).x] = '0';
    }
}

void SnakeBoard::Draw(){
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int SnakeBoard::GetLength(){
    return tail.size();
}

Point SnakeBoard::GetHead(){
    return head;
}

std::vector<Point> SnakeBoard::GetTail(){
    return tail;
}

void SnakeBoard::Move(Direction dir){
    // for (size_t i = 0; i < tail.size() - 2; i++)
    // {
    //     tail.at(i)=tail.at(i+1);
    // }
    // tail.at(tail.size()-1)=head;
    switch (dir)
    {
    case 1:
        head.x-=1;        
        break;
    case 2:
        head.y+=1;
        break;
    case 3:
        head.x+=1;
        break;
    case 4:
        head.y-=1;
        break;
    }
    board[head.y][head.x]='@';
}