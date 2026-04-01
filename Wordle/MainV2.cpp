// In this version words will be represented by bit fields

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
// #include <set>

bool StrCompare(std::string a, std::string b) { return a < b; }

int main(){
    std::vector<std::string> dict;
    std::string str;

    std::ifstream dictionary1("wordle-La.txt");
    std::ifstream dictionary2("wordle-Ta.txt");

    auto start = std::chrono::high_resolution_clock::now();
    while (std::getline(dictionary1, str))
    {
        dict.push_back(str);
    }
    dictionary1.close();
    while (std::getline(dictionary2, str))
    {
        dict.push_back(str);
    }
    dictionary2.close();

    std::sort(dict.begin(), dict.end(), StrCompare); // not really necessary, mainly for my comfort - can be deleted

    for (std::string w : dict)
        std::cout << w << "\n";

    std::cout << dict.size() << '\n';

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nExecution time: " << duration.count() << " microseconds\n";
}