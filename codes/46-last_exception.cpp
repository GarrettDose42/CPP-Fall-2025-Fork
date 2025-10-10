/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <vector>

int last(std::vector<int> input)
{
    /* Question: What should we do if the input vector
                 has no elements at all? */
    return input.at(input.size() - 1);
}

int main()
{
    std::vector<int> W{6, 10, 17};
    auto z{last(W)};
    std::cout << "z: " << z << std::endl;
    return 0;
}
