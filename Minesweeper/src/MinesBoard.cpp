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
        SetTile(temp_mines[i]/8,temp_mines[i]%8,'X');
        // std::cout<<temp_mines.at(i)<<" ";
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

// void Dig(MinesBoard real, /*MinesBoard visible, */int row, int column, bool gameOver)
// {
    // visible.SetTile(5, 6, '2');
    // real.SetTile(3, 3, '@');
    // std::cout<<"mayhaps "<<real.GetTile(3,3);
    // if(visible.GetTile(row,column)=='*'){
    //     if (real->GetTile(row, column) == 'X')
    //     {
    //         std::cout << "Mina!";
    //         gameOver = true;
    //     }
    //     else if (real.GetTile(row, column) == '0') // there goes all the stuff
    //     {//this wont work bacause mind two neighboring 0's
    //         visible.SetTile(row, column, 0);
    //         if (row > 0 && column > 0 && row < ROWS - 1 && column < COLUMNS - 1)
    //         { // here we go again
    //             Dig(real, visible, row - 1, column - 1, gameOver);
    //             Dig(real, visible, row - 1, column, gameOver);
    //             Dig(real, visible, row - 1, column + 1, gameOver);
    //             Dig(real, visible, row, column - 1, gameOver);
    //             Dig(real, visible, row, column + 1, gameOver);
    //             Dig(real, visible, row + 1, column - 1, gameOver);
    //             Dig(real, visible, row + 1, column, gameOver);
    //             Dig(real, visible, row + 1, column + 1, gameOver);
    //             std::cout << "test 0";
    //         }
    //         else if (row == 0 && column > 0 && column < COLUMNS - 1)
    //         { // edge case 1
    //             Dig(real, visible, row, column - 1, gameOver);
    //             Dig(real, visible, row, column + 1, gameOver);
    //             Dig(real, visible, row + 1, column - 1, gameOver);
    //             Dig(real, visible, row + 1, column, gameOver);
    //             Dig(real, visible, row + 1, column + 1, gameOver);
    //         }
    //         else if (row == ROWS - 1 && column > 0 && column < COLUMNS - 1)
    //         { // edge case 2
    //             Dig(real, visible, row - 1, column - 1, gameOver);
    //             Dig(real, visible, row - 1, column, gameOver);
    //             Dig(real, visible, row - 1, column + 1, gameOver);
    //             Dig(real, visible, row, column - 1, gameOver);
    //             Dig(real, visible, row, column + 1, gameOver);
    //         }
    //         else if (column == 0 && row > 0 && row < ROWS - 1)
    //         { // edge case 3
    //             Dig(real, visible, row - 1, column + 1, gameOver);
    //             Dig(real, visible, row, column + 1, gameOver);
    //             Dig(real, visible, row + 1, column + 1, gameOver);
    //             Dig(real, visible, row - 1, column, gameOver);
    //             Dig(real, visible, row + 1, column, gameOver);
    //         }
    //         else if (column == COLUMNS - 1 && row > 0 && row < ROWS - 1)
    //         { // edge case 4
    //             Dig(real, visible, row - 1, column - 1, gameOver);
    //             Dig(real, visible, row, column - 1, gameOver);
    //             Dig(real, visible, row + 1, column - 1, gameOver);
    //             Dig(real, visible, row - 1, column, gameOver);
    //             Dig(real, visible, row + 1, column, gameOver);
    //         }
    //         else if (row == 0 && column == 0)
    //         { // corner case 1
    //             Dig(real, visible, row, column + 1, gameOver);
    //             Dig(real, visible, row + 1, column, gameOver);
    //             Dig(real, visible, row + 1, column + 1, gameOver);
    //             std::cout<<"test 00 ";
    //         }
    //         else if (row == ROWS - 1 && column == 0)
    //         { // corner case 2
    //             Dig(real, visible, row - 1, column, gameOver);
    //             Dig(real, visible, row - 1, column + 1, gameOver);
    //             Dig(real, visible, row, column + 1, gameOver);
    //         }
    //         else if (row == 0 && column == COLUMNS - 1)
    //         { // corner case 3
    //             Dig(real, visible, row, column - 1, gameOver);
    //             Dig(real, visible, row + 1, column - 1, gameOver);
    //             Dig(real, visible, row + 1, column, gameOver);
    //         }
    //         else if (row == ROWS - 1 && column == COLUMNS - 1)
    //         { // corner case 4
    //             Dig(real, visible, row - 1, column, gameOver);
    //             Dig(real, visible, row - 1, column - 1, gameOver);
    //             Dig(real, visible, row, column - 1, gameOver);
    //         }
    //         else // Should not be necessary, but just in case
    //             std::cout << "Error. Now check all the ifs, this time in Dig()";
    //     }
    //     else
    //     {
    //         // visible.SetTile(row, column, real.GetTile(row, column));
    //         visible.SetTile(row,column,'2');
    //         visible.SetTile(5,5, '2');
    //         std::cout << "test 1 "<<real.GetTile(row,column);
    //     }
    // }
// }