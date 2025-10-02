/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

struct TimeOfDay
{
    unsigned int hour{0};
    unsigned int minute{0};
};

void print_time(const TimeOfDay &the_time)
{
    std::cout << the_time.hour << ":" << the_time.minute;
}

/* parse_time(input)
   Given a string, attempt to parse the contents into an hour and minute
   and return a TimeOfDay object containing the result.

   Exceptions should be thrown in the following cases. The cases
   must be checked in the order below.
    - If the string does not contain two numerical fields separated
      by a colon (e.g. "10:06" or "17:10", but not "6" or "10:"),
      throw std::domain_error (NOT std::invalid_argument).
    - If the hour is not in the range 0 - 23 or the minute is not
      in the range 0 - 59, throw std::out_of_range

    (For this exercise, assume that if std::stoi finishes successfully, the
     value returned is a valid numerical interpretation of the input string)
*/
TimeOfDay parse_time(const std::string &input)
{

    std::string before_colon{};
    std::string after_colon{};

    bool colon_found{false};

    for (const auto &c : input)
    {
        if (c == ':')
            colon_found = true;
        else
        {
            if (!colon_found)
                before_colon += c; // before_colon = c + before_colon
            else
                after_colon += c;
        }
    }

    // std::cout << "before_colon " << before_colon << std::endl;
    // std::cout << "after_colon " << after_colon << std::endl;

    // if (colon_found == false)
    // {
    //     std::domain_error error{"Missing colon"};
    //     throw error;
    // }

    if (!colon_found)
        throw std::domain_error{"Missing colon"};

    int hour{};
    int min{};

    // try
    // {
    //     hour = std::stoi(before_colon);
    //     min = std::stoi(after_colon);
    // }
    // catch (std::invalid_argument &e)
    // {
    //     throw std::domain_error{"Impossible to convert " + before_colon + " or " + after_colon + " to an integer"};
    // }

    try
    {
        hour = std::stoi(before_colon);
    }
    catch (std::invalid_argument &e)
    {
        throw std::domain_error{"Impossible to convert " + before_colon + " to an integer"};
    }

    try
    {
        min = std::stoi(after_colon);
    }
    catch (std::invalid_argument &e)
    {
        throw std::domain_error{"Impossible to convert " + after_colon + " to an integer"};
    }

    //at this point stoi succeded!

    if (hour < 0 || hour > 23)
        throw std::out_of_range{"Hour not in [0, 23]"};

    if (min < 0 || min > 59)
        throw std::out_of_range{"Min not in [0, 59]"};

    TimeOfDay res{};
    res.hour = hour;
    res.minute = min;
    return res;
}

int main()
{
    std::string input_string{};

    std::cout << "What time is it? ";
    std::getline(std::cin, input_string);
    std::cout << "You entered " << input_string << std::endl;

    try
    {
        // Task: Handle the error cases
        TimeOfDay T{parse_time(input_string)};
        std::cout << "The time is ";
        print_time(T);
        std::cout << std::endl;
    }
    catch (std::domain_error &e)
    {
        std::cout << "Something went badly " << e.what() << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << "Something went badly " << e.what() << std::endl;
    }

    return 0;
}
