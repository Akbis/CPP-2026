#include"MinesBoard.h"

// 10 mines
void Draw(MinesBoard Board)
{
    std::cout << "   ";
    for (int i = 0; i < COLUMNS + 1; i++)
    {

        for (int j = 0; j < ROWS + 2; j++)
        {
            if (j == 0 && i > 0)
                std::cout << i ;
            else if (j == 1 && i > 0)
                std::cout << "| ";

            if (i == 0 && j > 1)
                std::cout << (char)(j + 63) << " ";
            // else if (i==1 && j>1)
            //     std::cout<<"__";

            else if (i > 0 && j > 1)
                std::cout << Board.GetTile(i-1,j-2)<<" ";
        }
        std::cout << '\n';
    }
}

int main()
{
    // system("clear");
    srand(time(0));
    MinesBoard Board;
    Board.SetBoard();
    Draw(Board);

}
