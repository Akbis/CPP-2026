#include"SnakeBoard.h"
#include<ncurses.h>

Direction NcurInput(int input,SnakeBoard board){
    Direction dir;
    switch (input)
    {
    case KEY_RIGHT:
    case (int)'d':
        dir = RIGHT;
        break;
    case KEY_UP:
    case (int)'w':
        dir = UP;
        break;
    case KEY_LEFT:
    case (int)'a':
        dir = LEFT;
        break;
    case KEY_DOWN:
    case (int)'s':
        dir = DOWN;
        break;
    default:
        dir = board.GetDefaultDirection();
        break;
    }
    return dir;
}

void NcurDraw(SnakeBoard board,WINDOW* win){
    for(int i=0;i<HEIGHT;i++){
        for (int j = 0; j<WIDTH; j++)
        {
            if (board.GetTile(i, j) == '0' || board.GetTile(i, j) == '@'){
                wattron(win,COLOR_PAIR(1));
                mvwprintw(win, i + 1, 2 * j + 2, "%c", board.GetTile(i, j));
                wattroff(win,COLOR_PAIR(1));
            }
            else if (board.GetTile(i, j) == 'T'){
                wattron(win, COLOR_PAIR(2));
                mvwprintw(win, i + 1, 2 * j + 2, "%c", board.GetTile(i, j));
                wattroff(win,COLOR_PAIR(2));
            }
            else
                mvwprintw(win, i + 1, 2 * j + 2, "%c", board.GetTile(i, j));
        }
        
    }
    mvprintw(27, 25, "Score:");
    mvprintw(27, 53, "%d", board.Score());  
    wrefresh(win);
}

int main(){
    bool gameOver = false;
    int input;
    SnakeBoard board;

    system("resize -s 35 80");  // resize terminal
    system("clear");            // resize command prints new dimensions by default
    srand(time(0));             // seed

    initscr();
    noecho();               // don't display getch()
    curs_set(0);            // don't display cursor
    keypad(stdscr,true);    // allow inputing special keys
    set_escdelay(0);        // without this ESC causes delays

    // as long as there are no detected errors this solves timing problem
    timeout(135); // when theres no input for n miliseconds of a second it throws ERR which is equal -1,
    // can be verified by adding case -1: to NCurInput()

    // Colors
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    WINDOW *win=newwin(HEIGHT+2,2*WIDTH+3,5,19);
    refresh();
    box(win,0,0);
    wrefresh(win);

    while (!gameOver)
    {
        NcurDraw(board, win);
        input=getch();
        board.Move(NcurInput(input,board));

        if(board.IsGameLost()){
            gameOver=true;
            mvprintw(3,37,"Game Over");
            getch();
        }
        if(board.Score()==WIDTH*HEIGHT-2){
            gameOver=true;
            mvprintw(3, 37, "Wreszcie koniec");
            getch();
        }
    }
    timeout(-1);    // overrites timeout so that itwill wait indefinitely for input to close window

    getch();
    endwin();
}
