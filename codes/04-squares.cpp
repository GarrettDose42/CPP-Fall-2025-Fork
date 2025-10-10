/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>

int main()
{

    // While loop version
    int i = 0;
    while (i < 10)
    {
        std::cout << i << " squared is " << i * i << std::endl;
        i++;
    }

    // For loop version
    for (int j = 0; j < 10; j++)
    {
        std::cout << j << " squared is " << j * j << std::endl;
    }

    return 0;
}