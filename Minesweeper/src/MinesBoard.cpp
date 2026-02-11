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