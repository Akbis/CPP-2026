#include"SnakeBoard.h"

bool Point::operator==(Point & pt){
    return (x==pt.x && y==pt.y);
}

Direction OppositeDirection(Direction dir)
{
    switch (dir)
    {
    case 1:
        return LEFT;
        break;
    case 2:
        return UP;
        break;
    case 3:
        return RIGHT;
        break;
    case 4:
        return DOWN;
        break;
    default:
        return LEFT;
        break;
    }
}

SnakeBoard::SnakeBoard(){
    PlaceFruit();
    SyncBoard();
}

int SnakeBoard::Score(){
    return tail.size()-1;
}


void SnakeBoard::SyncBoard(){
    for (int i = 0; i < HEIGHT+1; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i+1][j] = ' ';  // not sure if it should be ' ' or '*'
        }
        board[head.y+1][head.x] = '@';
        board[fruit.y+1][fruit.x] = 'T';
        for (Point v : tail)
        {
            board[v.y+1][v.x] = '0';
        }
    }
}
void SnakeBoard::Move(Direction dir){
    if(dir!=OppositeDirection(defaultDirection)){
        Point curHead=head;
        switch (dir)
        {
        case 1:
            head.x += 1;
            defaultDirection=RIGHT;
            break;
        case 2:
            head.y += 1;
            defaultDirection = DOWN;
            break;
        case 3:
            head.x -= 1;
            defaultDirection = LEFT;
            break;
        case 4:
            head.y -= 1;
            defaultDirection = UP;
            break;
        }
        if(head==fruit){
            tail.push_back(curHead);
            PlaceFruit();
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
    else
        Move(defaultDirection);
}


void SnakeBoard::PlaceFruit(){
    std::vector<int> tiles_vector(WIDTH * HEIGHT); // same method as in Minesweeper
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
    if (head.x == -1 || head.x == WIDTH || head.y == -1 || head.y == HEIGHT)
    {
        return true;
    }
    for(Point v : tail){
        if (v==head)
        {
            return true;
        }      
    }
    return false;
}

Direction SnakeBoard::GetDefaultDirection(){
    return defaultDirection;
}

char SnakeBoard::GetTile(int y,int x){
    return board[y+1][x];
}