/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <vector>

struct InvalidGradeException
{
    unsigned int grade_index{}; //Index of the invalid grade
    int grade_value{};
    std::string idk{};
};

struct EmptyGradeArrayException
{
    //This structure has no members (but it can still be created and thrown)
};

/* average_grades( grades )
   Given a vector of grades (integers in the range 0 - 100),
   compute and return the average of all elements.

   Task: Improve this code to handle the following errors.
          - If the vector is empty, throw EmptyGradeArrayException
          - If any grades in the vector are invalid (negative or greater than
            100), throw an instance of InvalidGradeException containing the
            index of the first invalid grade in the vector.

*/
float average_grades(std::vector<int> const &grades)
{
    if (grades.size() <= 0)
    {
        throw EmptyGradeArrayException{};
    }

    float sum{0};
    for (unsigned int i{0}; i < grades.size(); i++)
    {
        const auto &g = grades.at(i);
        if (g < 0 || g > 100)
        {
            // InvalidGradeException ex{};
            // ex.grade_index = i;
            // ex.grade_value = g;

            // throw ex;

            throw InvalidGradeException{i, g, "blah"};
        }
        sum += g;
    }
    return sum / grades.size();
}

int main()
{

    std::vector<int> grades1{90, 70, 80};
    std::vector<int> grades2{};            //Invalid (can't average zero things)
    std::vector<int> grades3{90, 70, -80}; //Invalid (grades can't be negative)

    const auto &G = grades3;

    try
    {
        auto av{average_grades(G)};
        std::cout << "Average: " << av << std::endl;
    }
    catch (const EmptyGradeArrayException &e)
    {
        std::cout << ":(" << std::endl;
    }
    catch (const InvalidGradeException &e)
    {
        std::cout << "Invalid grade.at("
                  << e.grade_index << ")="
                  << e.grade_value << " not in [0,100]" << std::endl;
    }

    unsigned int val = 1;
    std::cout << val << std::endl;

    --val;
    std::cout << val << std::endl;

    --val;
    std::cout << val << std::endl;

    // for (unsigned long i{G.size() - 1}; i >= 0; --i)
    // {
    //     std::cout << i << " " << std::flush;
    //     std::cout << G.at(i) << std::endl;
    // }

    return 0;
}