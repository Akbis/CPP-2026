#include"MinesColors.h"

void PrintTiles(char tile){
    if(tile=='X'){
        std::cout<<REDBLACK<<tile<<RESET<<" ";
    }
    else if (tile == '0')
    {
        std::cout << BOLDWHITE << tile << RESET << " ";
    }
    else if (tile == '1')
    {
        std::cout << BOLDBLUE << tile << RESET << " ";
    }
    else if (tile == '2')
    {
        std::cout << BOLDGREEN << tile << RESET << " ";
    }
    else if (tile == '3')
    {
        std::cout << GREEN << tile << RESET << " ";
    }
    else if (tile == '4')
    {
        std::cout << BOLDYELLOW << tile << RESET << " ";
    }
    else if (tile == '5')
    {
        std::cout << MAGENTA << tile << RESET << " ";
    }
    else if (tile == '6')
    {
        std::cout << RED << tile << RESET << " ";
    }
    else if (tile == '7')
    {
        std::cout << BOLDRED << tile << RESET << " ";
    }
    else if (tile == '8')
    {
        std::cout << BOLDMAGENTA << tile << RESET << " ";
    }
    else
        std::cout << tile << " ";
}