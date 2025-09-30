/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <map>
#include <string>

int main()
{
    //Various ways to add new elements to a map

    //Method 1: Add {key, value} pairs when creating the map
    std::map<std::string, unsigned int> fruit_ratings{};

    //Method 2: Use .insert to add {key, value} pair objects

    //Method 3: Use the square bracket operator

    for (auto [name, rating] : fruit_ratings)
    {
        std::cout << name << ": " << rating << "/10" << std::endl;
    }

    return 0;
}
