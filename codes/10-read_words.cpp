/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <string>

int main()
{
    std::string word1{}, word2{};

    std::cout << "Enter two words: ";

    //Task: Read two words from the user into word1 and word2
    std::cin >> word1;
    std::cin >> word2;


    std::cout << "You entered [" << word1 << "] and [" << word2 << "]" << std::endl;
    return 0;
}
// "Hello "