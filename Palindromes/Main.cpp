#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::ifstream dictionary("/usr/share/dict/british-english");
    std::vector<std::string> dict,Palindromes;
    std::string str;
    bool isPalindrome = false;

    while (std::getline(dictionary, str)){
        if(str.length()!=1 && !((str.at(1)<91) && (str.at(1)>64)))  // remove 1 lettered words and abbreviations
            dict.push_back(str);
    }
    dictionary.close();

    for(std::string w:dict){
        isPalindrome = true;
        for(int i=0;i<w.length()/2;i++){
            if(w.at(i)!=w.at(w.length()-1-i)){
                isPalindrome = false;
                break;
            }
        }
        if(isPalindrome==true){
            Palindromes.push_back(w);
        }
    }

    for(std::string w:Palindromes){
        std::cout<<w<<"\n";
    }


}
