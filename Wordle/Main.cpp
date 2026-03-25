#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <set>

bool StrCompare(std::string a, std::string b) { return a < b; }
bool IsRepeatingLetters(std::string a); // checks if word have any repeating letters
bool HaveSameLetters(std::string a, std::string b); // checks if two words share any letters
bool hasAnagram(std::string str, std::vector<std::string> dict);
    std::vector<std::string> MatchingWords(std::string str, std::vector<std::string> dict); // finds all words in a dictionary that share no letters wit string
int main()
{

    std::vector<std::string> dict,temp;

    std::ifstream dictionary1("wordle-La.txt");
    std::ifstream dictionary2("wordle-Ta.txt");
    std::string str;
    // int size;
    // bool del=false;

    auto start = std::chrono::high_resolution_clock::now();
    while (std::getline(dictionary1, str))
    {
        if(!IsRepeatingLetters(str))
            dict.push_back(str);
    }
    dictionary1.close();
    while (std::getline(dictionary2, str))
    {
        if (!IsRepeatingLetters(str))
            dict.push_back(str);
    }
    dictionary2.close();

    
    // size=dict.size();
    std::sort(dict.begin(),dict.end(),StrCompare);
    temp = dict;
    // str=dict.at(0);
    // for(std::string str : dict){
        // for (size_t i=1;i<temp.size();i++){
        //     for (int j = 0; j < 5; j++){
        //         for(int h=0;h<5;h++){
        //             if(str.at(j)==temp.at(i).at(h)){
        //                 temp.erase(temp.begin()+i);
        //                 del=true;
        //                 i-=1;
        //                 break;
        //             }
        //         }
        //         if(del)
        //             break;
        //     }
        // }
    // }

    // for (size_t j = 0; j < 1; j++)
    // {
    //     temp=dict;
    //     for (size_t i = 1; i < temp.size(); i++)
    //     {
    //         if(HaveSameLetters(dict.at(j),temp.at(i))){
    //             temp.erase(temp.begin() + i);
    //             i -= 1;
    //         }

    //     }
    //     for (std::string w : temp)
    //         std::cout << w << "\n";

    //     std::cout  << "\n";
    // }



    for (std::string w : temp)
        std::cout << w << "\n";

    std::cout << temp.size() << '\n';

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nTime taken by function: " << duration.count() << " microseconds\n";
}

bool IsRepeatingLetters(std::string a){
    for (size_t i = 0; i < a.length() - 1; i++)
    {
        for (size_t j = i + 1; j < a.length(); j++)
        {
            if (a.at(i) == a.at(j))
                return true;
        }
    }
    return false;
}

bool HaveSameLetters(std::string a, std::string b){
    for(char c1 : a){
        for(char c2 : b){
            if(c1==c2)
                return true;
        }
    }
    return false;
}

bool hasAnagram(std::string str, std::vector<std::string> dict){
    std::sort(str.begin(), str.end());
    for (std::string word : dict){
        std::sort(word.begin(), word.end());
        if (str == word)
            return true;
    }
    return false'

}

std::vector<std::string> MatchingWords(std::string str, std::vector<std::string> dict){
    for (size_t i = 0; i < dict.size(); i++)
    {
        if (HaveSameLetters(str, dict.at(i)))
        {
            dict.erase(dict.begin() + i);
            i -= 1;
        }
    }
    dict.push_back(str);
    return dict;
}
