#include"SnakeBoard.h"

bool Point::operator==(Point & pt){
    return (x==pt.x && y==pt.y);
}

SnakeBoard::SnakeBoard(){
    PlaceFruit();
    SyncBoard();
}

void SnakeBoard::Draw(){
    for (int i = 0; i < HEIGHT; i++)
    {   
        std::cout<<" ";
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
    Point curHead=head;
    switch (dir)
    {
    case 1:
        head.x += 1;
        break;
    case 2:
        head.y += 1;
        break;
    case 3:
        head.x -= 1;
        break;
    case 4:
        head.y -= 1;
        break;
    }
    if(head==fruit){
        PlaceFruit();
        tail.push_back(curHead);
    }
    else{
    for (size_t i = 0; i < tail.size(); i++)
       {
           if(tail.at(i)==tail.back())
               tail.back() = curHead;
           else
               tail.at(i) = tail.at(i + 1);
       }
    }
    SyncBoard();
}

void SnakeBoard::Eat(){

}

void SnakeBoard::PlaceFruit(){
    std::vector<int> tiles_vector(WIDTH * HEIGHT);
    std::iota(tiles_vector.begin(), tiles_vector.end(), 0);
    std::vector<int> taken_tiles;

    taken_tiles.push_back(head.y * WIDTH + head.x);
    for (Point v : tail)
    {
        taken_tiles.push_back(v.y*WIDTH+v.x);
    }

    sort(taken_tiles.begin(), taken_tiles.end(), std::greater<int>());
    for (int v : taken_tiles)
    {
        tiles_vector.erase(tiles_vector.begin()+v);
    }

    std::random_shuffle(tiles_vector.begin(), tiles_vector.end());
    fruit={(int)tiles_vector[0]%HEIGHT,(int)tiles_vector[0]/WIDTH};

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