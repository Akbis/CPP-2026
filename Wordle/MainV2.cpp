// In this version words will be represented by bit fields

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <bitset>
#include <array>
#include <unordered_map>
struct encoded_word{
    std::string word;
    std::bitset<26> bword;
};
std::ostream &operator<<(std::ostream &out, const encoded_word &obj)
{
    int it = 0;
    for (auto c : obj.word)
    {
        out << c;
        ++it;
        if (!(it % 5))
            out << " ";
    }
    return out << obj.bword << "\n";
}

// bool StrCompare(std::string a, std::string b) { return a < b; }

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
    std::vector<bool> is_word(26 * 26 * 26 * 26 * 26);// real max value is actually 9999364 for word without repeating letters, but that probably doesn't matter all that much
    // std::vector<std::vector<std::string>> anagrams; // could be replaced by python style dictionary - i think in c++ those are maps
    std::unordered_map<int,std::vector<std::string>> anagrams_map; // this one is better, I think - int is hash, and vector contains all corresponding words
    // std::array<std::vector<std::string>, 26> alphabetical_words;

    auto start = std::chrono::high_resolution_clock::now();
    // std::ifstream dictionary("in_words.txt");
    std::ifstream dictionary("words_alpha_five.txt");

    while (!dictionary.eof())
    {
        std::string word;
        dictionary >> word;
        if(!has_unique_letters(word)) continue;
        int hash = getHash(word);
        if (is_word[hash]){
            anagrams_map[hash].push_back(word);
            continue;
        }
        anagrams_map.insert({hash, {word}});
        is_word[hash] = true;
        dict.push_back(word);
        encoded_word tmp_encoded = {word, encode(word)};
        // for(int i=0; i<26; i++)
        //     alphabetical_words[i].push_back(word);
        // for(int i=0; i<5; i++){
        //     alphabetical_words.at(word[i] - 'a').pop_back();
        // }
        words.push_back(tmp_encoded);        
    }

    int size = dict.size();
    
    // for confirmation that the map works correctly
    // for (auto it = anagrams_map.begin(); it != anagrams_map.end(); it++)
    // {
    //     std::cout << it->first << ": ";
    //     for (auto w : it->second)
    //         std::cout << w << " ";
    //     std::cout << "\n";
    // }

    // std::cout << anagrams_map.size() << "\n";
    // std::cout << size << "\n";

    
    std::vector<encoded_word> result;

    // MAIN LOOPS
    for(int i=0; i < size - 4; i++){

        for (int j=i+1; j < size - 3; j++){
            if((words[i].bword & words[j].bword) == 0){
                encoded_word double_word = { words[i].word + words[j].word,
                                             words[i].bword | words[j].bword };

                for(int k = j+1; k < size-2; k++){
                    if ((double_word.bword & words[k].bword) == 0){
                        encoded_word triple_word = {double_word.word + words[k].word,
                                                    double_word.bword | words[k].bword};

                        for (int l = k + 1; l < size-1; l++)
                        {
                            if ((triple_word.bword & words[l].bword) == 0)
                            {
                                encoded_word quad_word = {triple_word.word + words[l].word,
                                                            triple_word.bword | words[l].bword};

                                for (int m = l + 1; m < size; m++)
                                {
                                    if ((quad_word.bword & words[m].bword) == 0)
                                    {
                                        encoded_word pent_word = {quad_word.word + words[m].word,
                                                                  quad_word.bword | words[m].bword};
                                        result.push_back(pent_word);
                                    }
                                }
                            }
                        }
                        
                    }
                } 
            }
        }
    }

    // std::cout << result.size() << "\n";
    // for(auto w : result)
    //     std::cout << w;


    // adding anagrams back
    std::vector<std::array<std::string, 5>> final_words;
    for(auto w : result){
        std::array<std::string, 5> five_words;
        for(int i=0; i<5; i++){
            five_words[i] = w.word.substr(5*i, 5);
        }

        final_words.push_back(five_words);

        for (int i = 0; i < 5; i++){
            int word_hash = getHash(five_words[i]);
            std::vector<std::string> tmp_vect = anagrams_map.at(word_hash);
            if(tmp_vect.size() > 1){
                for(auto st : tmp_vect){
                    five_words[i] = st;
                    if (st != tmp_vect.front())
                        final_words.push_back(five_words);
                }
            }
        }
        
    }

    // Printing results
    std::ofstream outfile("results.txt");
    outfile << final_words.size();
    for(auto arr : final_words){
        for (auto w : arr)
        {
            outfile << w << " ";
        }
        outfile << "\n";
    }


    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    outfile << "\nExecution time: " << duration.count() << " microseconds\n";
}

/*
file - in_words.txt
10 without anagrams
brick jumpy glent vozhd waqfs 11011111111111111111111111 
chunk fjord waltz gymps vibex 11111111101111111111111111 
fjord nymph waltz gucks vibex 11111111101111111111111111 
jumpy bling treck vozhd waqfs 11011111111111111111111111 
prick glent jumby vozhd waqfs 11011111111111111111111111 
bemix clunk grypt vozhd waqfs 11111111111111110111111111 
blunk cimex grypt vozhd waqfs 11111111111111110111111111 
brung cylix kempt vozhd waqfs 11111111111111110111111111 
clipt jumby kreng vozhd waqfs 11011111111111111111111111 
jumby pling treck vozhd waqfs 11011111111111111111111111
Execution time: 629'794'311 microseconds
*/

/*
file alpha_words_five.txr
538 without anagrams
in file results.txt
Execution time: 1146'661'738 microseconds

*/