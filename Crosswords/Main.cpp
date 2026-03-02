#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char** argv){
    if (argc != 2)
    {
        std::cout<<"Błędna liczba argumentów\n";
        return 0;
    }
    std::string input = argv[1];

    std::cout << input.length() << "\n";

    std::ifstream dictionary("/usr/share/dict/polish");
    std::vector<std::string> dict;
    std::string str;

    while (std::getline(dictionary, str))
    {
        if (str.length() == input.length()) // Zawężenie obszaru wyszukiwania do słóœ o odpowiedniej długości
        {
            dict.push_back(str);
        }
        
    }
    for(std::string w:dict)
        std::cout<<w<<" "<<w.length()<<"\n";
    
    dictionary.close();
}