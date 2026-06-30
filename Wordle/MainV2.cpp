// In this version words will be represented by bit fields

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <bitset>
#include <array>
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
    // std::ifstream dictionary("words_alpha_five.txt");
    /*
    for consistency's sake first version of this will be made for in_words.txt which is a list of words used by NYT wordle
    later versions will use words_alpha_five.txt or full words_alpha.txt
    */


    auto start = std::chrono::high_resolution_clock::now();
    // IDEA : make array of vectors which will keep every word containing given letter array<vector<encoded_words>, 26> alphabetical_words
    
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

    std::vector<encoded_words> two_words_set;
    std::vector<encoded_words> three_words_set;
    /*
    it could be continued this way up to five words, but the problem is that there will be duplicates as (ab + cd) + (ef +gh) = (ab +ef) + (cd +gh)
    maybe this could be resolved by sorting or double checking
    */

    /* 
    another idea - not a very good one
    I could do straight five loops, but woth narrowing size of each loop
    next loop could iterate only over those words which have no common letters with result of previous loop
    another words - only those words that were matched will bo considered in next loop
    */

    /*
    checking if two words have no common letters could also be done by comparing logical and to 0
    */
    unsigned words_number = dict.size();
    std::vector<std::vector<encoded_words>> matched_words(words_number);  // for every word this stores words that have no letters in common
    // IDEA : encoded word could also have positions of stored words in dict
    for(int i=0; i< words_number-1; i++){ 
        // std::vector<encoded_words> matched_words;
        for(int j=i+1; j<dict.size(); j++){
            if((words[i].bword | words[j].bword) == (words[i].bword ^ words[j].bword)){
                two_words_set.push_back({words[i].word + words[j].word, words[i].bword | words[j].bword});
                // matched_words.push_back(words[j]);
                matched_words.at(i).push_back(words[j]);
            }
        }
        // for(int j=0; j<two_words_set.size(); j++){ // absolutely not that
        //     for(int k=0; k<matched_words.size(); k++){ // wrong two_words_set iteration
        //         if((two_words_set[j].bword | matched_words[k].bword) == (two_words_set[j].bword ^ matched_words[k].bword)){
        //             three_words_set.push_back({two_words_set[j].word + matched_words[k].word, two_words_set[j].bword | matched_words[k].bword});
        //         }
        //     }
        // }
    }
    // std::sort(dict.begin(), dict.end(), StrCompare); // not really necessary, mainly for my comfort - can be deleted

    // for (std::string w : dict)
    //     std::cout << w << "\n";

    std::cout << words_number << '\n'; //5182

    // for (auto w : words_set)
        // std::cout << w.word <<"  "<<w.bword << "\n";

    std::cout << two_words_set.size() << '\n'; //2367071
    int sum = 0;
    for(auto s : matched_words){
        sum += s.size();
        std::cout << s.size() << "\n";
    }
    std::cout << sum <<"\n";
    std::cout << matched_words.size() << "\n";
    // for (auto w : two_words_set)
        // std::cout << w.word <<"  "<<w.bword << "\n";
    std::cout<<two_words_set.size()<<'\n';

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nExecution time: " << duration.count() << " microseconds\n";
}

