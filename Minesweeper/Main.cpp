#include"MinesBoard.h"
#include"MinesColors.h"
#include<iomanip>
#include<string>

void Draw(MinesBoard Board);
void theDraw(MinesBoard Board);
void InputError(std::string coords);
std::vector<int> ParseInput();

int main()
{
    bool gameOver=false;

    // system("clear");
    srand(time(0));
    MinesBoard Board;
    Board.SetBoard();
    Draw(Board);
    while(!gameOver){
        theDraw(Board);
        std::vector<int> coordinates = ParseInput();
        Board.Dig(coordinates.at(1)-1,coordinates.at(0),gameOver);
        if (Board.GetTile(coordinates.at(1)-1, coordinates.at(0))=='X'){
            gameOver = true;
            std::cout<<"Game over\n";
        }
        
    }



    // Draw(Board);
    // theDraw(Board);
    // Board.Dig(2,3,gameOver);
    // theDraw(Board);
}

void Draw(MinesBoard Board)
{
    std::cout << "    ";
    for (int i = 0; i < COLUMNS + 1; i++)
    {

        for (int j = 0; j < ROWS + 2; j++)
        {
            if (j == 0 && i > 0)
            {
                std::cout << std::setw(2) << i;
            }
            else if (j == 1 && i > 0)
                std::cout << "| ";

            if (i == 0 && j > 1)
                std::cout << (char)(j + 63) << " ";

            else if (i > 0 && j > 1)
                PrintTiles(Board.GetTile(i - 1, j - 2));
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
                std::cout << std::setw(2) << i;
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

std::vector<int> ParseInput()
{
    std::string coords;
    std::cout << "Podaj współrzędne pola: ";
    std::getline(std::cin, coords);
    int x, y;
    std::vector<int> coordinates(2,-1);
    coords.erase(std::remove(coords.begin(), coords.end(), ' '), coords.end());
    std::cout<<coords<<'\n';
    if (coords.length() < 2)
    {
        std::cout << "Błędne współrzędne!\n";
        // std::cout << "Podaj poprawne współrzędne pola: ";
        coordinates = ParseInput();
    }

    // char xAxis=coords[0];
    // char yAxis;
    else
    {
        // x=(int)xAxis-64;
        x = toupper(coords.at(0)) - 65;
        std::cout<<x<<" :x\n";
        coordinates[0]=x;
        std::cout << coordinates[0]<<"\n";
        if (x < 1 || x > COLUMNS-1)
        {
            std::cout << "0";
            std::cout << "Błędne współrzędne!\n";
            // std::cout << "Podaj poprawne współrzędne pola: ";
            coordinates=ParseInput();
        }
        else{
            coords.erase(0, 1);
            try
            {
                y = std::stoi(coords);
                coordinates[1]=y;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "1";
                std::cout << "Błędne współrzędne!\n";
                // std::cout << "Podaj poprawne współrzędne pola: ";
                coordinates = ParseInput();
            }
            catch (const std::out_of_range &e)
            {
                std::cout << "2";
                std::cout << "Błędne współrzędne!\n";
                // std::cout << "Podaj poprawne współrzędne pola: ";
                coordinates = ParseInput(); 
            }
            if (y < 1 || y > ROWS )
            {
                std::cout << "0";
                std::cout << "Błędne współrzędne!\n";
                // std::cout << "Podaj poprawne współrzędne pola: ";
                coordinates = ParseInput();
            }
        }
    }
    return coordinates;
    // std::cout << "cdcd " << y << '\n';
    // std::cout << x << std::endl;
}
/* TODO:
1. implement reading user input
2. put logic into while loop on bool gameOver
3. imake flagging mines possible
4. add flavor text
5. make it so first tile discovered is always '0'
6. look into text formating, if posible add colors, also if cout cannot format output switch to printf      DONE
7. Clean up the code (get rid of Draw and theDraw, one is enough)
*/


