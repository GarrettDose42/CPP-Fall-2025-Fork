/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <vector>

void print_vector(const std::vector<int> &V)
{
    for (const int &x : V)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> V{1, 2, 3, 4, 5};

    const std::vector<int> &V_ref{V};

    V.at(1) = 42;

    //Task: Try uncommenting the line below. What happens?
    // V_ref.at(2) = 100;
    std::cout << V_ref.at(2) << std::endl;

    print_vector(V);
    print_vector(V_ref);

    return 0;
}