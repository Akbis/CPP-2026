#include"MinesBoard.h"

MinesBoard::MinesBoard(){
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            tiles[i][j]='k';
        }   
    }    
}

char MinesBoard::GetTile(int row, int column){
    return tiles[row][column];
}

void MinesBoard::SetTile(int row, int column, char value){
    tiles[row][column]=value;
}

void MinesBoard::SetBoard(){
    std::vector<int> temp_mines(ROWS*COLUMNS);
    std::iota(temp_mines.begin(),temp_mines.end(),0);
    std::random_shuffle(temp_mines.begin(),temp_mines.end());
    for(int i=0;i<number_of_mines;i++)
    {
        SetTile(temp_mines[i]/8,temp_mines[i]%8,'X');
        // std::cout<<temp_mines.at(i)<<" ";
    }
}