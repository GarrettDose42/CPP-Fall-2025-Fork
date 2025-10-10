/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <vector>

int main()
{
    std::vector<double> V{10.6, 11.4, 34.9, 5.6};
    std::vector<int> W{10, 5, 7, 8};

    // Question: What is the type of x and y?
    auto x{V.at(0)};//double
    auto y{W.at(0)};//int

    // Question: What is the y after the statement?
    y = V.at(1);//int so 11

    std::cout << "x is " << x << std::endl;
    std::cout << "y is " << y << std::endl;
}
