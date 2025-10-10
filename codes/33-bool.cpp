/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>

int main()
{
    int x{6};
    int y{10};

    bool q{true};

    if (q)
    {
        std::cout << "q is true" << std::endl;
    }
    else
    {
        std::cout << "q is false" << std::endl;
    }

    return 0;
}