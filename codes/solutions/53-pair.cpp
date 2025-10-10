/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <utility>
#include <string>

struct stringstring
{
    std::string first;
    std::string second;
};

struct stringint
{
    std::string first;
    int second;
};

struct intstring
{
    int first;
    std::string second;
};

int main()
{
    int a{5};
    std::string b{"Hello"};

    std::pair<int, std::string> p{a, b};
    std::pair<int, int> p1{a, a};

    //std::pair<int, std::string>
    auto p2 = std::make_pair(42, "blah");

    //std::pair<std::string, std::string>
    auto p3 = std::make_pair(b, b);

    std::cout << p.first << " " << p.second << std::endl;
    std::cout << p3.first << " " << p3.second << std::endl;

    std::cout << "Loooooooooooooook here" << std::endl;
    std::cout << p2.first << " " << p2.second << std::endl;

    auto &[f, s] = p2;
    std::cout << f << " " << s << std::endl;

    f = 666;
    std::cout << p2.first << " " << p2.second << std::endl;
    std::cout << "-------------------" << std::endl;

    p3.second = "World";
    std::cout << p3.first << " " << p3.second << std::endl;

    return 0;
}