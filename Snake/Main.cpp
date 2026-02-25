#include"SnakeBoard.h"
#include<ncurses.h>

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
void NcurDraw(SnakeBoard board,WINDOW* win){
    for(int i=0;i<HEIGHT;i++){
        for (int j = 0; j<WIDTH; j++)
        {
            mvwprintw(win, i + 1, 2 * j + 2, "%c", board.GetTile(i,j));
        }
        
    }
    wrefresh(win);

}

int main(){
    system("resize -s 35 80");  // resize terminal
    // bool gameOver=false;
    // system("clear");
    srand(time(0));
    SnakeBoard board;
    // char intput; 
    // board.Draw();
    // while(!gameOver){
    //     system("clear");
    //     board.Draw();
    //     std::cin>>intput;
    //     board.Move(Input(intput, board));
    //     gameOver = board.IsGameLost();
    // }
    // board.Move(UP);
    // board.Move(UP);
    // board.Draw();
    // board.Move(LEFT);
    // board.Draw();
    initscr();
    noecho();
    curs_set(0);
    // printw("Hello world");

    WINDOW *win=newwin(22,43,5,19);
    refresh();
    box(win,0,0);
    // for (int i = 0; i < HEIGHT; i++)
    // {
    //     for (int j = 0; j < WIDTH; j++)
    //     {
    //         mvwprintw(win, i + 1, 2 * j + 2, "%c", board.GetTile(j, i));
    //     }
    // }
    wrefresh(win);
    mvprintw(27, 25, "Score:");
    // mvprintw(27,53,"%d", score);  // use when scoring implemented
    NcurDraw(board,win);

    getch();
    endwin();
}


