#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::ifstream dictionary("/usr/share/dict/british-english");
    std::vector<std::string> dict;
    std::string str;
    // dictionary>>str;
    // getline(dictionary,str);
    // std::cout<<str;
    while (std::getline(dictionary, str)){
        if(str.length()!=1)
            dict.push_back(str);
    }
    dictionary.close();


    std::cout<<dict.size();
    // for(std::string w:dict)
        // std::cout<<w<<"\n";


}