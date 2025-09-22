#include <iostream>
#include <vector>
#include <string>

int main()
{
    //Task 0: Create a vector VS of string containing foo bar baz

    std::vector<std::string> VS{"foo","bar","baz"};

    //Task 1: Print the vector
    for (int i{0}; i < VS.size(); i++){
        std::cout << VS.at(i) << std::endl;
        //std::cout << VS.at(i).at(i) << std::endl;
    }


    //Task 2: Create big string by concatenating all the strings in the vector
    std::string big_string{};

        for (int i{0}; i < VS.size(); i++){
        big_string.append(VS.at(i));
    }


    //Task 3: Print the big string
    std::cout << big_string << std::endl;

    return 0;
}
