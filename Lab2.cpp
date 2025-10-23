#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::string repeat_string(const std::string& str, int num);
std::string reverse_string(void);
int check_palindrome(void);




int main() {
    
    std::string input{"hello"};
    int times{5};
    repeat_string(input, times);

    reverse_string();
    
    check_palindrome();

    return 0;
}

std::string repeat_string(const std::string& str, int num) {
    std::string result;
    std::cout << "string = " << str << std::endl;
    std::cout << "times = " << num << std::endl;
    for (int i = 0; i < num; ++i) {
        result += str;
    }
    std::cout << "\noutput = " << result << std::endl;
    return result;
}

std::string reverse_string(void){
    std::string str{"gnirts daer ot deliaf :rorrE"};
    std::string rts{};
    std::cout << "Enter String:" << std::endl;
    std::getline(std::cin, str);
    for(unsigned long i{str.length()}; i > 0; i-- ){
        rts += str.at(i-1);
    }
    std::cout << "Reverse of string is: " << rts << std::endl;
    return rts;
}

int check_palindrome(void){
    std::string str{""};
    std::vector<char> char_list {};
    std::cout << "Enter String:" << std::endl;
    std::getline(std::cin, str);
    std::cout <<"\"" << str << "\"";
    for(unsigned long i{}; i < str.length(); i++ ){
        if((std::isspace((unsigned char)str.at(i))) || std::ispunct((unsigned char)str.at(i))){
        str.erase(i,1);
        i--;
        }
    }
    for(unsigned long i{}; i < str.length()/2; i++ ){
        if(str.at(i) != str.at(str.length()-(i+1))){
            std::cout << "is NOT a palindrome" << std::endl;
            return 0;
        }
    }
    std::cout << " IS a palindrome" << std::endl;
    return 1;
}