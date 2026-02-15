#include"MinesColors.h"

void PrintTiles(char tile){
    switch (tile){
    case 'X':
        std::cout<<REDBLACK<<tile<<RESET<<" ";
        break;
    
    case '0': 
        std::cout << BOLDWHITE << tile << RESET << " ";
        break;
        
    case '1':  
        std::cout << BOLDBLUE << tile << RESET << " ";
        break;

    case '2':   
        std::cout << BOLDGREEN << tile << RESET << " ";
        break;

    case '3':   
        std::cout << GREEN << tile << RESET << " ";
        break;

    case '4':   
        std::cout << BOLDYELLOW << tile << RESET << " ";
        break;

    case '5':  
        std::cout << MAGENTA << tile << RESET << " ";
        break;

    case '6':   
        std::cout << RED << tile << RESET << " ";
        break;

    case '7':
        std::cout << BOLDRED << tile << RESET << " ";
        break;

    case '8':
        std::cout << BOLDMAGENTA << tile << RESET << " ";
        break;

    case 'F':
         std::cout << BOLDCYAN << tile << RESET << " ";
         break;

    default:
        std::cout << tile << " ";
        break;
    }
}