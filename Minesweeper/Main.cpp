#include"MinesBoard.h"
#include"MinesColors.h"
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
                // std::cout << Board.GetTile(i-1,j-2)<<" ";
                PrintTiles(Board.GetTile(i-1,j-2));
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
                PrintTiles(Board.GetShownTile(i - 1, j - 2));
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


