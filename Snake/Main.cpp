#include"SnakeBoard.h"
#include<curses.h>

Direction Input(int input){
    Direction dir;
    switch (input)
    {
    case 1:
        dir=RIGHT;
        break;
    case 2:
        dir=UP;
        break;
    case 3:
        dir=LEFT;
        break;
    case 4:
        dir=DOWN;
        break;
    
    default:
        break;

    }
    return dir;
}

int main(){
    bool gameOver=false;
    system("clear");
    srand(time(0));
    SnakeBoard board;
    int intput; 
    board.Draw();
    while(!gameOver){
        system("clear");
        board.Draw();
        std::cin>>intput;
        board.Move(Input(intput));
        gameOver = board.IsGameLost();
        
        

    }
    // board.Move(UP);
    // board.Move(UP);
    // board.Draw();
    // board.Move(LEFT);
    // board.Draw();

}


