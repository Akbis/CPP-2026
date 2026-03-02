#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::ifstream dictionary("/usr/share/dict/british-english");
    std::vector<std::string> dict,anagrams;
    std::string str;
    bool isAnagram = false;

    while (std::getline(dictionary, str)){
        if(str.length()!=1 && !((str.at(1)<91) && (str.at(1)>64)))  // remove 1 lettered words and abbreviations
            dict.push_back(str);
    }
    dictionary.close();

    for(std::string w:dict){
        isAnagram = true;
        for(int i=0;i<w.length()/2;i++){
            if(w.at(i)!=w.at(w.length()-1-i)){
                isAnagram = false;
                break;
            }
        }
        if(isAnagram==true){
            anagrams.push_back(w);
        }
    }

    for(std::string w:anagrams){
        std::cout<<w<<"\n";
    }


}