#include"SnakeBoard.h"

bool Point::operator==(Point & pt){
    return (x==pt.x && y==pt.y);
}

SnakeBoard::SnakeBoard(){
    Point tmpFruit={rand()%WIDTH,rand()%HEIGHT};
    while((tmpFruit == head)){
        tmpFruit = {rand() % WIDTH, rand() % HEIGHT};
    }
    fruit=tmpFruit;
    SyncBoard();
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

void SnakeBoard::SyncBoard(){
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = '*';
        }
        board[head.y][head.x] = '@';
        board[fruit.y][fruit.x] = 'T';
        for (Point v : tail)
        {
            board[v.y][v.x] = '0';
        }
    }
}
void SnakeBoard::Move(Direction dir){
    for (size_t i = 0; i < tail.size(); i++)
    {
        if(tail.at(i)==tail.back())
            tail.back() = head;
        else
            tail.at(i) = tail.at(i + 1);
    }

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
    SyncBoard();
    gameOver=IsGameLost(); //might be moved to main
}

bool SnakeBoard::IsGameLost(){
    if (head.x == -1 || head.x == WIDTH || head.y == -1 || head.x == HEIGHT)
    {
        std::cout<<"out of buonds!\n";
        return true;
    }
    for(Point v : tail){
        if (v==head)
        {
            std::cout<<"Ouroboros\n";
            return true;
        }      
    }
    return false;
}