#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

bool StrCompare(std::string a, std::string b) { return a < b; }
bool IsRepeatingLetters(std::string a); // checks if word have any repeating letters
bool HaveSameLetters(std::string a, std::string b); // checks if two words share any letters
std::vector<std::string> MatchingWords(std::string str, std::vector<std::string> dict); // finds all words in a dictionary that share no letters wit string
int CountVovels(std::string str); // IDEA: thers limited ammount of vovels and words cannot share letters, so I probbly could throw out words with too much of them

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
    // temp = dict;
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

    // temp = MatchingWords(temp.at(3), temp);
    // temp = MatchingWords(temp.at(0), temp);
    // temp = MatchingWords(temp.at(7), temp);
    std::vector<int> vovels={0,0,0,0,0,0};
    for (std::string w : dict){
        std::cout << w <<" " <<CountVovels(w)<<"\n";
        vovels.at(CountVovels(w))++;
        if(CountVovels(w)==4)
            temp.push_back(w);
    }

    std::cout << temp.size()<<'\n';
    for(int i : vovels)
        std::cout<<i<<" ";
    
        for (std::string w : temp)
        std::cout << w << "\n";

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

int CountVovels(std::string str){
    int count=0;
    for(char c : str){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' )
            count++;
    }
    return count;
}