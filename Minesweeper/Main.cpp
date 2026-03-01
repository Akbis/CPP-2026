#include"MinesBoard.h"
#include"MinesColors.h"
#include<iomanip>
#include<string>

void Uncover(MinesBoard Board);
void Draw(MinesBoard Board);
void InputError(std::string coords);
std::vector<int> ParseInput();

int main()
{
    bool gameOver=false;
    std::vector<int> coordinates;

    system("clear");
    srand(time(0));
    MinesBoard Board;

    // First move
    Draw(Board);
    coordinates=ParseInput();
    Board.SetBoard(coordinates.at(1) - 1, coordinates.at(0));
    Board.Dig(coordinates.at(1) - 1, coordinates.at(0));
    system("clear");
    Draw(Board);
 
    // Every other move
    while(!gameOver){
        
        coordinates = ParseInput();
        if (Board.GetShownTile(coordinates.at(1) - 1, coordinates.at(0)) == '*' || Board.GetShownTile(coordinates.at(1) - 1, coordinates.at(0)) == 'F')
        {
            Board.ChooseAction(coordinates.at(1) - 1, coordinates.at(0));
            system("clear");
            Draw(Board);
        }
        else{
            std::cout << "Błędne współrzędne! Wybrane pole jest już odkryte\n";
        }

        if (Board.IsGameLost()){
            gameOver = true;
            std::cout<<"Game over\n";
            Uncover(Board);
        }
        if(Board.IsGameWon()){
            gameOver = true;
            std::cout << "Wreszcie koniec, gratulacje\n";
            Uncover(Board);
        }   
    }
}

void Uncover(MinesBoard Board)
{
    std::cout << "\n    ";
    for (int i = 0; i < ROWS + 1; i++)
    {

        for (int j = 0; j < COLUMNS + 2; j++)
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

void Draw(MinesBoard Board)
{
    std::cout << "\n    ";
    for (int i = 0; i < ROWS + 1; i++)
    {

        for (int j = 0; j < COLUMNS + 2; j++)
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
    int x, y;
    std::vector<int> coordinates(2, -1);
    std::cout << "Podaj współrzędne pola: ";
    std::getline(std::cin, coords);
    // std::cin.clear();
    // std::cin.sync();
    coords.erase(std::remove(coords.begin(), coords.end(), ' '), coords.end()); //Usuwanie spacji

    if (coords.length() < 2) // Sprawdzenie minimalnej długości
    {
        std::cout << "Błędne współrzędne!\n";
        coordinates = ParseInput();
    }
    else
    {
        x = toupper(coords.at(0)) - 65;

        if (!(x >= 0 && x < COLUMNS)) // Sprawdzenie czy pierwsza koordynata jest poprawna
        {
            std::cout <<"Błędne współrzędne!\n";
            coordinates=ParseInput();
        }
        else{
            coordinates[0] = x;
            coords.erase(0, 1);
            try
            {
                y = std::stoi(coords); // std::stoi zinterpretuje przykładowy string 43gew4ff jako 43. Można dodać sprawdzenie ilości znaków przez 1+log10()
                coordinates[1]=y;
            }
            catch (const std::invalid_argument &e)
            {
                std::cout  << "Błędne współrzędne!\n";
                coordinates = ParseInput();
            }
            catch (const std::out_of_range &e)
            {
                std::cout  << "Błędne współrzędne!\n";
                coordinates = ParseInput(); 
            }

            if (coordinates[1] < 1 || coordinates[1] > ROWS ) 
            {
                std::cout  << "Błędne współrzędne!\n";
                coordinates = ParseInput();
            }
        }
    }
    return coordinates;
}