#define ROWS 8
#define COLUMNS 8
#include <iostream>
#include"MinesBoard.h"

// 10 mines
void Draw(char Board[ROWS][COLUMNS])
{
    std::cout << "   ";
    for (int i = 0; i < COLUMNS + 1; i++)
    {

        for (int j = 0; j < ROWS + 2; j++)
        {
            if (j == 0 && i > 0)
                std::cout << i - 1;
            else if (j == 1 && i > 0)
                std::cout << "| ";

            if (i == 0 && j > 1)
                std::cout << (char)(j + 63) << " ";
            // else if (i==1 && j>1)
            //     std::cout<<"__";

            else if (i > 0 && j > 1)
                std::cout << "* ";
        }
        std::cout << '\n';
    }
}

int main()
{
    // system("clear");
    char Board[ROWS][COLUMNS];
    Draw(Board);
}
