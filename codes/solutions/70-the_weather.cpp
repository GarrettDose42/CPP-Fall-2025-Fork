/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <map>
#include <string>
#include <utility>

void print_weather(const std::map<std::string, std::string> &w)
{
    std::cout << w.at("Victoria") << std::endl;
}

int main()
{
    std::map<std::string, std::string> the_weather{};
    the_weather.insert({"Victoria", "Rainy"});
    the_weather.insert({"Vancouver", "Rainy"});
    the_weather.insert({"Duncan", "Overcast"});
    the_weather.insert({"Campbell River", "Foggy"});

    std::cout << "Part 1" << std::endl;

    std::cout << "In Victoria, it is " << the_weather["Victoria"] << std::endl;
    if (the_weather.count("Nanaimo") > 0)
        std::cout << "In Nanaimo, it is [" << the_weather["Nanaimo"] << "]" << std::endl;

    // the_weather["Toronto"] = "Snow"

    std::cout << "Part 2" << std::endl;
    for (const auto &[city, conditions] : the_weather)
    {
        std::cout << "In [" << city << "], conditions are [" << conditions << "]" << std::endl;
    }

    return 0;
}