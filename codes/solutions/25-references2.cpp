/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>

void F(int x)
{
    x = x + 6;
}
void G(int &x)
{
    x = x + 10;
}

int GOOD(int x)
{
    return x + 10;
}

int main()
{
    int Z{0};
    std::cout << "Z = " << Z << std::endl;

    F(Z);
    std::cout << "Z = " << Z << std::endl;

    G(Z);
    std::cout << "Z = " << Z << std::endl;

    int &W{Z};
    G(W);
    std::cout << "Z = " << Z << std::endl;

    W = GOOD(W);

    return 0;
}
