#include"SnakeBoard.h"
#include<curses.h>

Direction Input(char input, SnakeBoard board){
    Direction dir;
    switch (input)
    {
    case 'd':
        dir=RIGHT;
        break;
    case 'w':
        dir=UP;
        break;
    case 'a':
        dir=LEFT;
        break;
    case 's':
        dir=DOWN;
        break;
    default:
        dir=board.GetDefaultDirection();
        break;

    }
    return dir;
}

int main(){
    bool gameOver=false;
    system("clear");
    srand(time(0));
    SnakeBoard board;
    char intput; 
    board.Draw();
    while(!gameOver){
        system("clear");
        board.Draw();
        std::cin>>intput;
        board.Move(Input(intput, board));
        gameOver = board.IsGameLost();
        
        

    }
    // board.Move(UP);
    // board.Move(UP);
    // board.Draw();
    // board.Move(LEFT);
    // board.Draw();

}


