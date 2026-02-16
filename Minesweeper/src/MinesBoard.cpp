#include"MinesBoard.h"

MinesBoard::MinesBoard(){ 
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            tiles[i][j]='*';
            shownTiles[i][j]='*';
        }   
    }    
}

char MinesBoard::GetTile(int row, int column){
    return tiles[row][column];
}

void MinesBoard::SetTile(int row, int column, char value){
    tiles[row][column]=value;
}

char MinesBoard::GetShownTile(int row, int column)
{
    return shownTiles[row][column];
}

void MinesBoard::SetShownTile(int row, int column, char value)
{
    shownTiles[row][column] = value;
}

void MinesBoard::SetBoard(){
    //Setting mines, if entire funcions becomes unreadable move this part to its own function SetMines()
    std::vector<int> temp_mines(ROWS*COLUMNS);
    std::iota(temp_mines.begin(),temp_mines.end(),0);
    std::random_shuffle(temp_mines.begin(),temp_mines.end());
    for(int i=0;i<number_of_mines;i++)
    {
        SetTile(temp_mines[i]/COLUMNS,temp_mines[i]%COLUMNS,'X');
    }

    //Setting tiles
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            tiles[i][j] = CountSurroundingMines(i,j);
        }
    }
}

void MinesBoard::SetBoard(int row,int column){
    std::vector<int> temp_mines(ROWS * COLUMNS);
    std::vector<int> surrounding_tiles;
    std::iota(temp_mines.begin(), temp_mines.end(), 0);

    surrounding_tiles.push_back(COLUMNS * row + column);
    if(row==0){
        surrounding_tiles.push_back(COLUMNS * (row + 1) + column);
        if (column==0)
        {
            surrounding_tiles.push_back(COLUMNS * row + column+1);
            surrounding_tiles.push_back(COLUMNS * (row+1) + column+1);
        }
        else if (column==COLUMNS-1)
        {
            surrounding_tiles.push_back(COLUMNS * (row + 1) + column-1);
            surrounding_tiles.push_back(COLUMNS * row + column-1);
        }
        else{
            surrounding_tiles.push_back(COLUMNS * row + column + 1);
            surrounding_tiles.push_back(COLUMNS * (row + 1) + column + 1);
            surrounding_tiles.push_back(COLUMNS * (row + 1) + column - 1);
            surrounding_tiles.push_back(COLUMNS * row + column - 1);
        }
        
        
    }
    else if(row==ROWS-1){
        surrounding_tiles.push_back(COLUMNS * (row - 1) + column);
        if (column == 0)
        {
            surrounding_tiles.push_back(COLUMNS * row + column + 1);
            surrounding_tiles.push_back(COLUMNS * (row - 1) + column + 1);
        }
        else if (column == COLUMNS-1)
        {
            surrounding_tiles.push_back(COLUMNS * (row - 1) + column - 1);
            surrounding_tiles.push_back(COLUMNS * row + column - 1);
        }
        else
        {
            surrounding_tiles.push_back(COLUMNS * row + column + 1);
            surrounding_tiles.push_back(COLUMNS * (row - 1) + column + 1);
            surrounding_tiles.push_back(COLUMNS * (row - 1) + column - 1);
            surrounding_tiles.push_back(COLUMNS * row + column - 1);
        }
    }
    else{
        surrounding_tiles.push_back(COLUMNS * (row + 1) + column);
        surrounding_tiles.push_back(COLUMNS * (row - 1) + column);
        if (column == 0)
        {
            surrounding_tiles.push_back(COLUMNS * row + column + 1);
            surrounding_tiles.push_back(COLUMNS * (row - 1) + column + 1);
            surrounding_tiles.push_back(COLUMNS * (row + 1) + column + 1);
        }
        else if (column == COLUMNS-1)
        {
            surrounding_tiles.push_back(COLUMNS * row + column - 1);
            surrounding_tiles.push_back(COLUMNS * (row - 1) + column - 1);
            surrounding_tiles.push_back(COLUMNS * (row + 1) + column - 1);
        }
        else
        {
            surrounding_tiles.push_back(COLUMNS * row + column + 1);
            surrounding_tiles.push_back(COLUMNS * (row - 1) + column + 1);
            surrounding_tiles.push_back(COLUMNS * (row + 1) + column + 1);
            surrounding_tiles.push_back(COLUMNS * row + column - 1);
            surrounding_tiles.push_back(COLUMNS * (row - 1) + column - 1);
            surrounding_tiles.push_back(COLUMNS * (row + 1) + column - 1);
        }
    }
    for(int v:surrounding_tiles){
        std::cout<<v<<" ";
    }
    std::cout<<"\n";
}

// This one is an abomination, should kill it with fire but it works
// Possibly could be done with vector of chars filled by functoin Surrounding(), but this implementation would work only for this function
// Using vector of pointers to tiles probably would be better, maybe will do it in GUI version if it happens
char MinesBoard::CountSurroundingMines(int row, int column){ // returning char cause mines
    int count = 0;  // will be converted to char ASCII for 0 is 48
    if(tiles[row][column]=='X'){
        return 'X';
    }
    else if (row>0 && column>0 && row<ROWS-1 && column<COLUMNS-1){ // there probably is a better way, but idgaf
        if(tiles[row-1][column-1]=='X') count++; 
        if(tiles[row-1][column]=='X') count++;
        if(tiles[row-1][column+1]=='X') count++;
        if(tiles[row][column-1]=='X') count++;
        if(tiles[row][column+1]=='X') count++;
        if(tiles[row+1][column-1]=='X') count++;
        if(tiles[row+1][column]=='X') count++;
        if(tiles[row+1][column+1]=='X') count++;
    }
    else if (row==0 && column>0 && column<COLUMNS-1){ //edge case 1
        if(tiles[row][column-1]=='X') count++;
        if(tiles[row][column+1]=='X') count++;
        if(tiles[row+1][column-1]=='X') count++;
        if(tiles[row+1][column]=='X') count++;
        if(tiles[row+1][column+1]=='X') count++;
    }
    else if (row==ROWS-1 && column>0 && column<COLUMNS-1){ //edge case 2
        if(tiles[row-1][column-1]=='X') count++; 
        if(tiles[row-1][column]=='X') count++;
        if(tiles[row-1][column+1]=='X') count++;
        if(tiles[row][column-1]=='X') count++;
        if(tiles[row][column+1]=='X') count++;
    }
    else if (column==0 && row>0 && row<ROWS-1){ //edge case 3 
        if(tiles[row-1][column]=='X') count++; 
        if(tiles[row-1][column+1]=='X') count++;
        if(tiles[row][column+1]=='X') count++;
        if(tiles[row+1][column]=='X') count++;
        if(tiles[row+1][column+1]=='X') count++;
    }
    else if (column==COLUMNS-1 && row>0 && row<ROWS-1){ //edge case 4
        if(tiles[row-1][column-1]=='X') count++;
        if(tiles[row-1][column]=='X') count++;
        if(tiles[row][column-1]=='X') count++;
        if(tiles[row+1][column-1]=='X') count++;
        if(tiles[row+1][column]=='X') count++;
    }
    else if (row==0 && column==0){ //corner case 1
        if(tiles[row][column+1]=='X') count++;
        if(tiles[row+1][column]=='X') count++;
        if(tiles[row+1][column+1]=='X') count++;
    }
    else if (row==ROWS-1 && column==0){ //corner case 2
        if(tiles[row][column+1]=='X') count++;
        if(tiles[row-1][column]=='X') count++;
        if(tiles[row-1][column+1]=='X') count++;
    }
    else if (row==0 && column==COLUMNS-1){ //corner case 3
        if(tiles[row+1][column]=='X') count++; 
        if(tiles[row][column-1]=='X') count++;
        if(tiles[row+1][column-1]=='X') count++;
    }
    else if (row==ROWS-1 && column==COLUMNS-1){ //corner case 4
        if(tiles[row][column-1]=='X') count++; 
        if(tiles[row-1][column]=='X') count++;
        if(tiles[row-1][column-1]=='X') count++;
    }
    else // Should not be necessary, but just in case
        std::cout<<"Error. Now check all the ifs";
    
    return (char)(count+48);
}

void MinesBoard::Dig(int row, int column)
{

    if (GetShownTile(row, column) == '*' || GetShownTile(row, column) == 'F')
    {
        if (GetTile(row, column) == 'X')
        {
            isGameLost=true;
        }
        else if (GetTile(row, column) == '0') // there goes all the stuff
        {
            SetShownTile(row, column, '0');
            uncovered_tiles++;
            if (row > 0 && column > 0 && row < ROWS - 1 && column < COLUMNS - 1)
            { // here we go again
                Dig(row - 1, column - 1);
                Dig(row - 1, column);
                Dig(row - 1, column + 1);
                Dig(row, column - 1);
                Dig(row, column + 1);
                Dig(row + 1, column - 1);
                Dig(row + 1, column);
                Dig(row + 1, column + 1);
            }
            else if (row == 0 && column > 0 && column < COLUMNS - 1)
            { // edge case 1
                Dig(row, column - 1);
                Dig(row, column + 1);
                Dig(row + 1, column - 1);
                Dig(row + 1, column);
                Dig(row + 1, column + 1);
            }
            else if (row == ROWS - 1 && column > 0 && column < COLUMNS - 1)
            { // edge case 2
                Dig(row - 1, column - 1);
                Dig(row - 1, column);
                Dig(row - 1, column + 1);
                Dig(row, column - 1);
                Dig(row, column + 1);
            }
            else if (column == 0 && row > 0 && row < ROWS - 1)
            { // edge case 3
                Dig(row - 1, column + 1);
                Dig(row, column + 1);
                Dig(row + 1, column + 1);
                Dig(row - 1, column);
                Dig(row + 1, column);
            }
            else if (column == COLUMNS - 1 && row > 0 && row < ROWS - 1)
            { // edge case 4
                Dig(row - 1, column - 1);
                Dig(row, column - 1);
                Dig(row + 1, column - 1);
                Dig(row - 1, column);
                Dig(row + 1, column);
            }
            else if (row == 0 && column == 0)
            { // corner case 1
                Dig(row, column + 1);
                Dig(row + 1, column);
                Dig(row + 1, column + 1);
            }
            else if (row == ROWS - 1 && column == 0)
            { // corner case 2
                Dig(row - 1, column);
                Dig(row - 1, column + 1);
                Dig(row, column + 1);
            }
            else if (row == 0 && column == COLUMNS - 1)
            { // corner case 3
                Dig(row, column - 1);
                Dig(row + 1, column - 1);
                Dig(row + 1, column);
            }
            else if (row == ROWS - 1 && column == COLUMNS - 1)
            { // corner case 4
                Dig(row - 1, column);
                Dig(row - 1, column - 1);
                Dig(row, column - 1);
            }
            else // Should not be necessary, but just in case
                std::cout << "Error. Now check all the ifs, this time in Dig()";
        }
        else
        {
            uncovered_tiles++;
            SetShownTile(row,column,GetTile(row,column));
        }
    }
}

bool MinesBoard::IsGameWon(){
    return !(ROWS*COLUMNS-uncovered_tiles-number_of_mines);
}

bool MinesBoard::IsGameLost(){
    return isGameLost;
}



void MinesBoard::ChooseAction(int x, int y)
{
    std::cout << "Wybierz akcję:\n";
    std::cout << "Z - Odkryj pole    X - Oflaguj pole\n";
    std::string input;
    std::getline(std::cin, input);
    while (input.length() > 1)
    {
        std::cout << "Błędny argument\n";
        std::cout << "Podaj poprawny argument: ";
        std::getline(std::cin, input);
    }
    char action = toupper(input.at(0));
    switch (action)
    {
    case 'Z':
        // std::cout << action;
        Dig(x, y);
        break;
    case 'X':
        SetShownTile(x, y, 'F');
        break;
    default:
        std::cout << "Błędny argument\n";
        std::cout << "Podaj poprawny argument: ";
        ChooseAction(x, y);
        break;
    }
}