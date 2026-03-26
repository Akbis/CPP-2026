#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <set>

bool StrCompare(std::string a, std::string b) { return a < b; }
bool IsRepeatingLetters(std::string a); // checks if word have any repeating letters
bool HaveSameLetters(std::string a, std::string b); // checks if two words share any letters
bool hasAnagram(std::string str, std::vector<std::string> dict); // checks is dictionary contains any anagram of given word
std::vector<std::string> MatchingWords(std::string str, std::vector<std::string> dict); // finds all words in a dictionary that share no letters wit string

int main(){

    std::vector<std::string> dict,temp;

    std::ifstream dictionary1("wordle-La.txt");
    std::ifstream dictionary2("wordle-Ta.txt");
    std::string str;


    auto start = std::chrono::high_resolution_clock::now();
    while (std::getline(dictionary1, str))
    {
        if(!IsRepeatingLetters(str) && !hasAnagram(str, dict))
            dict.push_back(str);
    }
    dictionary1.close();
    while (std::getline(dictionary2, str))
    {
        if (!IsRepeatingLetters(str) && !hasAnagram(str,dict))
            dict.push_back(str);
    }
    dictionary2.close();

    
    std::sort(dict.begin(),dict.end(),StrCompare); // not really necessary, mainly for my comfort - can be deleted
    temp = dict;

    int size = dict.size();
    std::vector<std::string> two_words;
    for(int i=0; i<size-1; i++){
        for(int j=i; j<size; j++){
            if(!HaveSameLetters(dict.at(i),dict.at(j)))
                two_words.push_back(dict.at(i)+dict.at(j));
        }
    }

    int two_size = two_words.size();
    std::vector<std::string> four_words;
    for (int i = 0; i < two_size - 1; i++)
    {
        std::cout << i << "  ";

        for (int j = i + 1; j < two_size; j++)
        {

            if (!HaveSameLetters(two_words.at(i), two_words.at(j)))
                                 four_words.push_back(two_words.at(i) + two_words.at(j));
        }
    }
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
//2367071
    //     for (std::string w : two_words)
    //         std::cout << w << "\n";

    // std::cout << two_words.size() << '\n';

    for (std::string w : four_words)
        std::cout << w << "\n";

    std::cout << four_words.size() << '\n';

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
    short freq[26] = {0};

    for (char c1 : a)
        freq[c1 - 'a']++;

    for (char c2 : b)
        freq[c2 - 'a']++;

    for (short i : freq)
    {
        if (i == 2)
            return true;
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
    return false;
}

    std::vector<std::string> MatchingWords(std::string str, std::vector<std::string> dict)
{
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
