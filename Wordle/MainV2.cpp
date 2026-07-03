// In this version words will be represented by bit fields

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <bitset>
#include <array>
struct encoded_word{
    std::string word;
    std::bitset<26> bword;
};
std::ostream& operator<<(std::ostream &out, const encoded_word &obj){
    return out << obj.word << " " << obj.bword << "\n";
}

// std::bitset<26> encode(std::string word);
// bool StrCompare(std::string a, std::string b) { return a < b; }
// int getHash(std::string word);
bool has_unique_letters(std::string word){
    bool letters_are_unique = true;
    std::sort(word.begin(), word.end());
    for (int i = 0; i < 4; i++)
    {
        if (word[i] == word[i + 1])
        {
            letters_are_unique = false;
            break;
        }
    }
    return letters_are_unique;
}
int getHash(std::string word){
    int hash = 0;
    std::sort(word.begin(), word.end());
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
    std::vector<encoded_word> words;
    std::vector<bool> is_word(26*26*26*26*26);
    std::array<std::vector<encoded_word>, 26> alphabetical_words;

    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream dictionary("in_words.txt");
    while (!dictionary.eof())
    {
        std::string word;
        dictionary >> word;
        if(!has_unique_letters(word)) continue;
        int hash = getHash(word);
        if (is_word[hash])
            continue;
        is_word[hash] = true;
        dict.push_back(word);
        encoded_word tmp_encoded = {word, encode(word)};
        for(int i=0; i<5; i++){
            alphabetical_words.at(word[i] - 'a').push_back(tmp_encoded);
        }
        words.push_back(tmp_encoded);        
    }
    


    for(auto w : alphabetical_words[16])
        std::cout << w;
    // std::cout << alphabetical_words[0].size() << "\n";
    for(int i=0; i<26; i++)
        std::cout << (char)('a' + i) << " " << alphabetical_words[i].size() << "\n";
    // auto start = std::chrono::high_resolution_clock::now();
    // IDEA : make array of vectors which will keep every word containing given letter array<vector<encoded_word>, 26> alphabetical_words
    // BETTER IDEA: instead vectors should contain words that does not have this letter
    // for(auto w : dict)
    //     std::cout <<w <<"\n";
    std::cout << dict.size() << '\n';
    /* 
    another idea - not a very good one
    I could do straight five loops, but woth narrowing size of each loop
    next loop could iterate only over those words which have no common letters with result of previous loop
    another words - only those words that were matched will bo considered in next loop
    */

    /*
    checking if two words have no common letters could also be done by comparing logical and to 0
    */

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nExecution time: " << duration.count() << " microseconds\n";
}

