#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */
#include"MinesBoard.h"
#include<iomanip>

void Draw(MinesBoard Board)
{
    std::cout << "    ";
    for (int i = 0; i < COLUMNS + 1; i++)
    {

        for (int j = 0; j < ROWS + 2; j++)
        {
            if (j == 0 && i > 0){
                std::cout <<std::setw(2)<< i ;
            }
            else if (j == 1 && i > 0)
                std::cout << "| ";

            if (i == 0 && j > 1)
                std::cout << (char)(j + 63) << " ";

            else if (i > 0 && j > 1)
                std::cout << Board.GetTile(i-1,j-2)<<" ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void theDraw(MinesBoard Board)
{
    std::cout << "    ";
    for (int i = 0; i < COLUMNS + 1; i++)
    {

        for (int j = 0; j < ROWS + 2; j++)
        {
            if (j == 0 && i > 0)
            {
                 std::cout <<std::setw(2)<< i ;
            }
            else if (j == 1 && i > 0)
                std::cout << "| ";

            if (i == 0 && j > 1)
                std::cout << (char)(j + 63) << " ";
                
            else if (i > 0 && j > 1)
                std::cout << Board.GetShownTile(i - 1, j - 2) << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main()
{
    bool gameOver=false;
    system("clear");
    srand(time(0));
    MinesBoard Board;
    Board.SetBoard();
    Draw(Board);
    theDraw(Board);
    Board.Dig(2,3,gameOver);
    theDraw(Board);
}

/* TODO:
1. implement reading user input
2. put logic into while loop on bool gameOver
3. imake flagging mines possible
4. add flavor text
5. make it so first tile discovered is always '0'
6. look into text formating, if posible add colors, also if cout cannot format output switch to printf
7. Clean up the code (get rid of Draw and theDraw, one is enough)
*/


