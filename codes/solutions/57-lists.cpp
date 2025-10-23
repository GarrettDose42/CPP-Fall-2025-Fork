/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <list>
#include <string>

/* element_at_index(L, idx)
   Return a reference to the element of the list L at
   the provided index. If the provided index is out of
   range, throw an instance of std::out_of_range.
*/
const std::string &element_at_index(const std::list<std::string> &L, unsigned int idx)
{
    std::cout << "using const" << std::endl;
    unsigned int index = 0;
    for (auto &v : L)
    {
        if (index == idx)
        {
            return v;
        }

        ++index;
    }

    throw std::out_of_range{"Invalid index"};
}

std::string &element_at_index(std::list<std::string> &L, unsigned int idx)
{

    std::cout << "using non const" << std::endl;
    unsigned int index = 0;
    for (auto &v : L)
    {
        if (index == idx)
        {
            return v;
        }

        ++index;
    }

    throw std::out_of_range{"Invalid index"};
}

int main()
{
    std::list<std::string> fruit{};

    //Add two elements to the end
    fruit.push_back("Raspberry");
    fruit.push_back("Cranberry");

    //Add two elements to the beginning
    fruit.push_front("Pineapple");
    fruit.push_front("Strawberry");

    //Add another element to the end
    fruit.push_back("Pineapple");

    //Print out the elements of the list
    std::cout << "Part 1: ";
    // for (auto s : fruit)
    // {
    //     std::cout << s << " ";
    // }
    // std::cout << std::endl;
    for (auto it = fruit.begin(); it != fruit.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //Task: Print out the first and last elements,
    //      then delete them from the list.
    std::cout << "last fruit " << fruit.back() << std::endl;
    // std::cout << "last fruit " << *fruit.end() << std::endl; //this DOES NOT work
    std::cout << "last fruit " << *fruit.rbegin() << std::endl;
    std::cout << "first fruit " << fruit.front() << std::endl;
    std::cout << "first fruit " << *fruit.begin() << std::endl;

    fruit.pop_back();
    fruit.pop_front();

    //Print out the elements of the list
    std::cout << "Part 2: ";
    for (auto s : fruit)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    //Task: Insert the value "Pear" as the third
    //      element of the list (before "Cranberry")
    auto it = fruit.begin();
    ++it;
    ++it;
    // it += 2;
    fruit.insert(it, "Pear");

    std::cout << "Part 3: ";
    for (auto s : fruit)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    //Task: Complete the element_at_index function
    //      above, then use it to print out the element
    //      at index 2 and modify the element at index
    //      3 to be "Guava".

    std::cout << "Element at index 2: " << element_at_index(fruit, 2) << std::endl;

    element_at_index(fruit, 3) = "Guava";
    // std::string &third = element_at_index(fruit, 3);
    // third = "Guava";

    //V.at(3) = "blah";

    std::cout << "Part 4: ";
    for (auto s : fruit)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
