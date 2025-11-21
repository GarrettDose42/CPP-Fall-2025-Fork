#include <iostream>
#include <vector>
#include <cctype>
#include <unordered_set>

int punctuation(const std::vector<std::string> &input);
int str_reverse();

int main(){
    std::vector<std::string> in{"Sea", "Shore,", "sea", "shell's.", "SHORE.", "line!"};
    punctuation(in);
    str_reverse();


    return 0;
}

int punctuation(const std::vector<std::string> &input){
    std::unordered_set<char> punct{};
    for(std::string word: input){
        for(char chr: word){
            if (ispunct(chr))
            {
                punct.insert(chr);
            }
        }
    }
    for(char p: punct){
        std::cout << p << " ";
    }
    std::cout << std::endl;
    return 0;
}

int str_reverse(void){
    std::string input{};
    getline(std::cin, input);
    std::string::iterator it{};
    for(it = input.end(); it != input.begin(); it--){
        std::cout << *it;
    }
    std::cout << *it << std::endl;
    return 0;
}