/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <string>
#include <vector>

/* print_vector( V )
   Print out each element in a vector of ints, in forward order.
*/
void print_vector(const std::vector<int> &V)
{

    // for (auto x : V)
    // {
    //     std::cout << x << " ";
    // }
    // std::cout << std::endl;

    // Task: Rewrite this using an iterator instead of a for-each loop
    //auto is *not* an int
    // auto it = V.begin();
    // while (it != V.end())
    // {
    //     int v = *it;
    //     std::cout << v << " ";
    //     it++;
    // }
    // std::cout << std::endl;

    for (auto it = V.begin(); it != V.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // int first = V.front();
}

/* print_reverse( V )
   Print out each element in a vector of ints, in reverse order.
*/
void print_reverse(std::vector<int> V)
{
    // Task: Write this without using indices
    for (auto it = V.rbegin(); it != V.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> V{6, 8, 10, 17};

    std::cout << "Before : ";
    print_vector(V);

    std::vector<int>::iterator iter = V.begin();
    // std::vector<int>::const_iterator iter = V.begin();

    std::cout << "Part 1: iter refers to " << *iter << std::endl;

    int first = V.front();
    std::cout << "Part 1: first refers to " << first << std::endl;
    V.erase(iter);

    int back = V.back();
    std::cout << "Part 1: back refers to " << back << std::endl;

    std::cout << "After: ";
    print_vector(V);

    iter = V.begin();
    ++iter;
    V.insert(iter, 42);

    std::cout << "After after: ";
    print_vector(V);

    // iter = V.begin();
    // iter += 3;
    // V.insert(iter, 666);

    V.insert(V.begin() + 3, 666);
    std::cout << "After after after: ";
    print_vector(V);

    std::cout << "In reverse: ";
    print_reverse(V);

    std::cout << "last: ";
    V.pop_back();
    print_vector(V);

    return 0;
}
