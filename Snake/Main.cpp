#include"SnakeBoard.h"
#include<curses.h>


int main(){
    srand(time(0));
    SnakeBoard board;
    board.Draw();
    board.Move(UP);
    board.Move(UP);
    board.Move(UP);
    board.Move(UP);
    board.Move(UP);
    board.Move(UP);
    board.Draw();


}

