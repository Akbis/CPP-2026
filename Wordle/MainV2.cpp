// In this version words will be represented by bit fields

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <bitset>
struct encoded_words{
    std::string word;
    std::bitset<26> bword;
};

// std::bitset<26> encode(std::string word);
// bool StrCompare(std::string a, std::string b) { return a < b; }
// int getHash(std::string word);
int getHash(std::string word){
    int hash = 0;
    for(int i=0; i<5; i++){
        hash = hash*26 + (word[i] - 'a');
    }
    return hash;
}

std::bitset<26> encode(std::string word){
    std::bitset<26> res(0);
    for(int i=0; i<5; i++){
        res.set(word[i] - 'a');
    }
    return res;
}

int main(){

    /* Loading words && removing anagrams*/
    std::vector<std::string> dict;
    std::vector<encoded_words> words;
    std::vector<bool> is_word(26*26*26*26*26);

    std::ifstream dictionary("in_words.txt");

    auto start = std::chrono::high_resolution_clock::now();
    while (!dictionary.eof())
    {   
        std::string word;
        dictionary >> word;
        bool has_different_letters = false;
        std::string tmp = word;
        std::sort(tmp.begin(), tmp.end());
        for (int i=0; i<4; i++){
            if(tmp[i] == tmp[i+1]){
                has_different_letters = true;
                break;
            }
        }
        if(has_different_letters) continue;
        int hash = getHash(tmp);
        if(is_word[hash]) continue;
        is_word[hash] = true;
        dict.push_back(word);
        words.push_back({word, encode(word)});



    }
    dictionary.close();


    // std::sort(dict.begin(), dict.end(), StrCompare); // not really necessary, mainly for my comfort - can be deleted

    for (std::string w : dict)
        std::cout << w << "\n";

    std::cout << dict.size() << '\n';

        for (auto w : words)
        std::cout << w.word <<"  "<<w.bword << "\n";

    std::cout << words.size() << '\n';


    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nExecution time: " << duration.count() << " microseconds\n";
}

