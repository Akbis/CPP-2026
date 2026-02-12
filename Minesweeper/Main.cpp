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
    std::cout << '\n';
}

int main()
{
    bool gameOver=false;
    // system("clear");
    srand(time(0));
    MinesBoard BoardReal,BoardVirtual;
    BoardReal.SetBoard();
    Draw(BoardReal);
    Draw(BoardVirtual);
    // BoardVirtual.SetTile(1,1,'k');
    Dig(BoardReal,BoardVirtual,0,0,gameOver);
    Draw(BoardReal);
    Draw(BoardVirtual);
}

void Dig(MinesBoard real, MinesBoard visible, int row, int column, bool gameOver)
{
    if (real.GetTile(row, column) == 'X')
    {
        std::cout << "Mina!";
        gameOver = true;
    }
    else if (real.GetTile(row, column) == '0') // there goes all the stuff
    {//this wont work bacause mind two neighboring 0's
        visible.SetTile(row, column, 0);
        if (row > 0 && column > 0 && row < ROWS - 1 && column < COLUMNS - 1)
        { // here we go again
            Dig(real, visible, row - 1, column - 1, gameOver);
            Dig(real, visible, row - 1, column, gameOver);
            Dig(real, visible, row - 1, column + 1, gameOver);
            Dig(real, visible, row, column - 1, gameOver);
            Dig(real, visible, row, column + 1, gameOver);
            Dig(real, visible, row + 1, column - 1, gameOver);
            Dig(real, visible, row + 1, column, gameOver);
            Dig(real, visible, row + 1, column + 1, gameOver);
            std::cout << "test 0";
        }
        else if (row == 0 && column > 0 && column < COLUMNS - 1)
        { // edge case 1
            Dig(real, visible, row, column - 1, gameOver);
            Dig(real, visible, row, column + 1, gameOver);
            Dig(real, visible, row + 1, column - 1, gameOver);
            Dig(real, visible, row + 1, column, gameOver);
            Dig(real, visible, row + 1, column + 1, gameOver);
        }
        else if (row == ROWS - 1 && column > 0 && column < COLUMNS - 1)
        { // edge case 2
            Dig(real, visible, row - 1, column - 1, gameOver);
            Dig(real, visible, row - 1, column, gameOver);
            Dig(real, visible, row - 1, column + 1, gameOver);
            Dig(real, visible, row, column - 1, gameOver);
            Dig(real, visible, row, column + 1, gameOver);
        }
        else if (column == 0 && row > 0 && row < ROWS - 1)
        { // edge case 3
            Dig(real, visible, row - 1, column + 1, gameOver);
            Dig(real, visible, row, column + 1, gameOver);
            Dig(real, visible, row + 1, column + 1, gameOver);
            Dig(real, visible, row - 1, column, gameOver);
            Dig(real, visible, row + 1, column, gameOver);
        }
        else if (column == COLUMNS - 1 && row > 0 && row < ROWS - 1)
        { // edge case 4
            Dig(real, visible, row - 1, column - 1, gameOver);
            Dig(real, visible, row, column - 1, gameOver);
            Dig(real, visible, row + 1, column - 1, gameOver);
            Dig(real, visible, row - 1, column, gameOver);
            Dig(real, visible, row + 1, column, gameOver);
        }
        else if (row == 0 && column == 0)
        { // corner case 1
            Dig(real, visible, row, column + 1, gameOver);
            Dig(real, visible, row + 1, column, gameOver);
            Dig(real, visible, row + 1, column + 1, gameOver);
        }
        else if (row == ROWS - 1 && column == 0)
        { // corner case 2
            Dig(real, visible, row - 1, column, gameOver);
            Dig(real, visible, row - 1, column + 1, gameOver);
            Dig(real, visible, row, column + 1, gameOver);
        }
        else if (row == 0 && column == COLUMNS - 1)
        { // corner case 3
            Dig(real, visible, row, column - 1, gameOver);
            Dig(real, visible, row + 1, column - 1, gameOver);
            Dig(real, visible, row + 1, column, gameOver);
        }
        else if (row == ROWS - 1 && column == COLUMNS - 1)
        { // corner case 4
            Dig(real, visible, row - 1, column, gameOver);
            Dig(real, visible, row - 1, column - 1, gameOver);
            Dig(real, visible, row, column - 1, gameOver);
        }
        else // Should not be necessary, but just in case
            std::cout << "Error. Now check all the ifs, this time in Dig()";
    }
    else
    {
        visible.SetTile(row, column, real.GetTile(row, column));
        std::cout << "test 1";
    }
}