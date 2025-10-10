/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <string>

int main()
{
    std::string the_line{};

    while (std::getline(std::cin, the_line))
    {
        std::cout << "The line was [" << the_line << "]" << std::endl;
    }

    return 0;
}
