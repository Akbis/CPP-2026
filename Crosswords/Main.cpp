#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// int BetterLenght(std::string word){ // Might be usefull if i tried in polish
//     int num_code_points = 0;
//     for (char byte : word)
//     {
//         if ((byte & 0xC0) != 0x80)
//         {
//             num_code_points++;
//         }
//     }
//     return num_code_points;
// }

int main(int argc, char** argv){
    if (argc != 2)
    {
        std::cout<<"Błędna liczba argumentów\n";
        return 0;
    }

    int number_of_results=0;
    bool isMatching;
    std::string input = argv[1];
    std::vector<std::string> dict,results;

    std::ifstream dictionary("/usr/share/dict/british-english");
    std::string str;

    while (std::getline(dictionary, str))
    {
        if (str.length() == input.length() && str.at(str.length()-2) != '\'') // Zawężenie obszaru wyszukiwania do słóœ o odpowiedniej długości
        {
            dict.push_back(str);
        }
        
    }
    dictionary.close();
    
    for(std::string w:dict)
    {
        isMatching=true;
        for (size_t i = 0; i < input.length(); i++)
        {   
            if (input.at(i) != '_' && input.at(i) != w.at(i))
            {
                isMatching=false;
                break;                
            }
        }
        if(isMatching){
            number_of_results++;
            results.push_back(w);
        }
    }

    std::cout<<number_of_results<<" results found:\n";
    for(std::string w:results)
        std::cout<<w<<"\n";


}