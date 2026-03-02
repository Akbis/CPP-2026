#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int BetterLenght(std::string word){
    int num_code_points = 0;
    for (char byte : word)
    {
        if ((byte & 0xC0) != 0x80)
        {
            num_code_points++;
        }
    }
    return num_code_points;
}

int main(int argc, char** argv){
    if (argc != 2)
    {
        std::cout<<"Błędna liczba argumentów\n";
        return 0;
    }
    std::string input = argv[1];

    for(size_t i=0;i<input.length();i++){
        std::cout<<input.at(i)<<" "; //as expected deos not work

    }

    std::cout << input.length() << "\n";

    std::ifstream dictionary("/usr/share/dict/polish");
    std::vector<std::string> dict;
    std::string str;

    while (std::getline(dictionary, str))
    {
        if (BetterLenght(str) == BetterLenght(input)) // Zawężenie obszaru wyszukiwania do słóœ o odpowiedniej długości
        {
            dict.push_back(str);
        }
        
    }
    // for(std::string w:dict)
        // std::cout<<w<<" "<<BetterLenght(w)<<"\n";
    
    dictionary.close();
}