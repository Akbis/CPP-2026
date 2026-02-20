#include"SnakeBoard.h"
#include<curses.h>


int main(){
    // bool gameOver=false;
    system("clear");
    srand(time(0));
    SnakeBoard board;
    board.Draw();
    board.Move(UP);
    board.Move(UP);
    board.Draw();
    board.Move(LEFT);
    board.Draw();


}

