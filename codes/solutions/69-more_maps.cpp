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
    std::map<std::string, unsigned int> fruit_ratings{{"Banana", 80},
                                                      {"Apple", 70},
                                                      {"Kiwi", 20}};

    //Method 2: Use .insert to add {key, value} pair objects
    fruit_ratings.insert(std::pair<std::string, unsigned int>{"Pear", 5});
    fruit_ratings.insert(std::make_pair("Apricot", 70));
    fruit_ratings.insert({"Cherry", 40});

    //Method 3: Use the square bracket operator
    fruit_ratings["Pineapple"] = 40;

    for (const auto &[name, rating] : fruit_ratings)
    {
        std::cout << name << ": " << rating << "/100" << std::endl;
    }

    return 0;
}
