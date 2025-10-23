/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <unordered_set>
#include <string>

int main()
{
    std::unordered_set<std::string> fruit{};
    fruit.insert("Raspberry");

    fruit.insert("Pear");
    fruit.insert("Cranberry");
    fruit.insert("Strawberry");
    fruit.insert("Pineapple");
    fruit.insert("Guava");
    fruit.insert("Lemon");
    fruit.insert("Orange");

    fruit.insert("Kiwi");
    fruit.insert("Apple");

    //std::unordered_set has (generally) faster insertion and
    //find times than std::set, but does not guarantee any
    //particular ordering of elements.
    for (auto x : fruit)
    {
        std::cout << "Element: " << x << std::endl;
    }

    return 0;
}
