#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <set>
// bool IsRepeatingLetters(std::string a);
// bool hasAnagrams(std::string a, std::vector<std::string> dict);

int main()
{
    std::vector<std::string> dict;
    std::vector<std::set<char>> setdict;

    std::ifstream dictionary1("wordle-La.txt");
    std::ifstream dictionary2("wordle-Ta.txt");
    std::string str;
    
    auto start = std::chrono::high_resolution_clock::now();
    while (std::getline(dictionary1, str))
    {
        std::set<char> setword(str.begin(),str.end());
        if(setword.size() == 5 && (std::count(setdict.begin(), setdict.end(),setword) == 0)){
            setdict.push_back(setword);
            dict.push_back(str);
        }
        // if(!IsRepeatingLetters(str))
            // dict.push_back(str);

    }
    dictionary1.close();
    while (std::getline(dictionary2, str))
    {
        // if (!IsRepeatingLetters(str))
            // dict.push_back(str);
        std::set<char> setword(str.begin(), str.end());
        if (setword.size() == 5 && (std::count(setdict.begin(), setdict.end(), setword) == 0)){
            setdict.push_back(setword);
            dict.push_back(str);
        }
    }
    dictionary2.close();

    std::cout<<setdict.size()<<std::endl;
    std::cout << dict.size() << std::endl;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nTime taken by function: " << duration.count() << " microseconds\n";
}

// bool IsRepeatingLetters(std::string a){
//     for (size_t i = 0; i < a.length() - 1; i++)
//     {
//         for (size_t j = i + 1; j < a.length(); j++)
//         {
//             if (a.at(i) == a.at(j))
//                 return true;
//         }
//     }
//     return false;
// }

// bool HaveSameLetters(std::string a, std::string b){
//     for(char c1 : a){
//         for(char c2 : b){
//             if(c1==c2)
//                 return true;
//         }
//     }
//     return false;
// }

// std::vector<std::string> MatchingWords(std::string str, std::vector<std::string> dict){
//     for (size_t i = 0; i < dict.size(); i++)
//     {
//         if (HaveSameLetters(str, dict.at(i)))
//         {
//             dict.erase(dict.begin() + i);
//             i -= 1;
//         }
//     }
//     dict.push_back(str);
//     return dict;
// }

// int CountVovels(std::string str){
//     int count=0;
//     for(char c : str){
//         if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' )
//             count++;
//     }
//     return count;
// }

// bool hasAnagrams(std::string a, std::vector<std::string> dict){
//
//}