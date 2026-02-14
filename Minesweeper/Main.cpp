#include"MinesBoard.h"
#include"MinesColors.h"
#include<iomanip>
#include<string>

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

void ParseInput(std::string coords){
    int x, y;
    coords.erase(std::remove(coords.begin(), coords.end(), ' '), coords.end());
    // std::cout<<coords<<'\n';
    if(coords.length()<2){
        // std::cout<<coords<<'\n';
        std::cout << "Błędne współrzędne!\n";
        std::cout << "Podaj poprawne współrzędne pola: ";
        std::getline(std::cin, coords);
        ParseInput(coords);
    }
    // std::vector<int> coordinates;
    // char xAxis=coords[0];
    // char yAxis;
    else{
        // x=(int)xAxis-64;
        x=toupper(coords.at(0))-64;
        if(x<1 || x>COLUMNS){
            std::cout << "Błędne współrzędne!\n";
            std::cout << "Podaj poprawne współrzędne pola: ";
            std::getline(std::cin, coords);
            ParseInput(coords);
        }
        coords.erase(0,1);
        y=std::stoi(coords);
        std::cout<<"cdcd "<<y<<'\n';
        std::cout<<x<<std::endl;
    }
}

int main()
{
    bool gameOver=false;
    std::string coords;
    char xAxis,yAxis;

    system("clear");
    srand(time(0));
    MinesBoard Board;
    Board.SetBoard();

    std::cout<< "Podaj współrzędne pola: ";
    std::getline(std::cin,coords);
    // std::cin>>coords;
    ParseInput(coords);

    // Draw(Board);
    // theDraw(Board);
    // Board.Dig(2,3,gameOver);
    // theDraw(Board);
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


