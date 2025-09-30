/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <stdexcept>

int F(int x)
{
    if (x > 10)
    {
        throw std::runtime_error{"Something bad happened."};
    }
    return x * 10;
}

int G(int y)
{
    int result{0};
    while (y < 100)
    {
        result += F(y);
        y = 2 * y;
    }
    return result;
}

int main()
{

    int y{999};
    y = G(6);

    std::cout << "y is " << y << std::endl;

    return 0;
}
