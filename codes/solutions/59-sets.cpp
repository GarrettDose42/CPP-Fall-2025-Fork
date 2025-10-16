/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set<std::string> fruit{};

    /* Add some elements to the set */
    fruit.insert("Raspberry");
    fruit.insert("Pear");
    fruit.insert("Cranberry");
    fruit.insert("Strawberry");
    fruit.insert("Pineapple");
    fruit.insert("Guava");
    fruit.insert("Lemon");
    fruit.insert("Orange");

    /* Task 1: Print out the size */
    std::cout << fruit.size() << std::endl;

    /* Task 2: Add the same element repeatedly and print the size again */
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    fruit.insert("Lemon");
    std::cout << fruit.size() << std::endl;

    /* Task 3: Try iterating over the set with a for-each loop */
    for (const auto &f : fruit)
    {
        std::cout << f << std::endl;
    }

    std::cout << "-------------------" << std::endl;

    /* Task 4a: Search for the values "Lemon" and "Lime" using .contains */
    // if (fruit.contains("Lemon"))
    //     std::cout << "Lemon is there" << std::endl;
    // else
    //     std::cout << "Lemon is NOT there" << std::endl;

    // if (fruit.contains("Lime"))
    //     std::cout << "Lime is there" << std::endl;
    // else
    //     std::cout << "Lime is NOT there" << std::endl;

    /* Task 4b: Search for the values "Lemon" and "Lime" using .count */
    // if (fruit.count("Lemon") > 0)
    //     std::cout << "Lemon is there" << std::endl;
    // else
    //     std::cout << "Lemon is NOT there" << std::endl;

    // if (fruit.count("Lime") > 0)
    //     std::cout << "Lime is there" << std::endl;
    // else
    //     std::cout << "Lime is NOT there" << std::endl;

    /* Task 4c: Search for the values "Lemon" and "Lime" using .find */
    if (fruit.find("Lemon") != fruit.end())
        std::cout << "Lemon is there" << std::endl;
    else
        std::cout << "Lemon is NOT there" << std::endl;

    if (fruit.find("Lime") != fruit.end())
        std::cout << "Lime is there" << std::endl;
    else
        std::cout << "Lime is NOT there" << std::endl;

    /* Task 5: Attempt to delete the values "Lemon" and "Grapefruit" */
    fruit.erase("Lemon");
    bool was_removed = fruit.erase("Grapefruit") > 0;
    std::cout << "-------------------" << std::endl;
    for (const auto &f : fruit)
    {
        std::cout << f << std::endl;
    }
    std::cout << "-------------------" << std::endl;

    /* Task 6: Insert the values "Lime" and "Raspberry", using the return
               value of .insert to check whether the element was already
               present */
    auto [lime_it, lime_was_inserted] = fruit.insert("Lime");
    std::cout << "was lime inserted? " << lime_was_inserted << std::endl;

    auto [raspberry_it, raspberry_was_inserted] = fruit.insert("Raspberry");
    std::cout << "was raspberry inserted? " << raspberry_was_inserted << std::endl;

    return 0;
}
