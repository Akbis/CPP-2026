#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

bool StrCompare(std::string a, std::string b) { return a < b; }
bool RepeatsLetters(std::string a){
    for(size_t i=0;i<a.length()-1;i++){
        for (size_t j = i+1; j < a.length(); j++){
            if(a.at(i)==a.at(j))
                return true;
        }
    }
    return false;
}

int main(){

    std::vector<std::string> dict,temp;

    std::ifstream dictionary1("wordle-La.txt");
    std::ifstream dictionary2("wordle-Ta.txt");
    std::string str;
    // int size;
    // bool del=false;

    auto start = std::chrono::high_resolution_clock::now();
    while (std::getline(dictionary1, str))
    {
        if(!RepeatsLetters(str))
            dict.push_back(str);
    }
    dictionary1.close();
    while (std::getline(dictionary2, str))
    {
        if (!RepeatsLetters(str))
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

    for (std::string w : temp)
        std::cout << w << "\n";
    std::cout<<temp.size();

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nTime taken by function: "<< duration.count() << " microseconds\n";
}