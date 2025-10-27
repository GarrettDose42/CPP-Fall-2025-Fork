/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <map>
#include <string>

int main()
{
    // std::map is an associative array, and is parameterized
    // by two types, a "key type" and a "value type".

    // The student_names object maps strings to strings
    std::map<std::string, std::string> student_names{};

    // To add a (key, value) pair to a map, the square bracket
    // operator can be used. If the provided key is not found,
    // it is added.

    // student_names[0] = "Alastair Avocado";
    student_names["V00123456"] = "Alastair Avocado";
    student_names["V00123457"] = "Rebecca Raspberry";
    student_names["V00654322"] = "Hannah Hindbaer";
    student_names["V00654321"] = "Meredith Malina";

    // The exam_grades object maps strings (student IDs)
    // to ints (grades)
    std::map<std::string, int> exam_grades{};

    exam_grades["V00123456"] = 63;
    exam_grades["V00123457"] = 91;
    exam_grades["V00654322"] = 87;
    exam_grades["V00654321"] = 87;

    // The value associated with any key can be retrieved
    // using the square bracket operator or the .at() function.

    // Task 1: Print out the name and grade of the student with
    //         Student ID "V00654322"

    std::cout << "Name from Vnum V00654322 " << student_names.at("V00654322") << std::endl;
    std::cout << "Name from Vnum V00654322 " << student_names["V00654322"] << std::endl;

    // Entries in a map can be changed as needed (equivalent
    // to a regular array or vector).
    // Like vectors, maps have the .at function, which is similar
    // to the square brackets but does not automatically
    // create the key.

    // Task 2: Alter the grade associated with V00654322
    //         to the value 89.

    std::cout << "Name from Vnum V00654322 " << exam_grades["V00654322"] << std::endl;

    std::cout << "Changing V00654322's grade..." << std::endl;
    // exam_grades["V00654322"] = 89;
    exam_grades.at("V00654322") = 89;

    // Repeat Task 1 to print out the updated information.
    std::cout << "Name from Vnum V00654322 " << exam_grades["V00654322"] << std::endl;

    std::cout << std::endl;

    // Task 3: Use for-each loops to print out each map.
    //         The first loop should print a list of IDs and names,
    //         and the second loop should print IDs and grades.
    std::cout << "Student Names: " << std::endl;
    // for (const std::pair<std::string, std::string> &v : student_names)
    // for (const auto &v : student_names)
    // {
    //     //auto [vnum, name] = v;
    //     std::cout << v.first << " has name " << v.second << std::endl;
    // }
    for (const auto &[vnum, name] : student_names)
    {
        std::cout << vnum << " has name " << name << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Exam Grades: " << std::endl;
    for (const auto &[vnum, grade] : exam_grades)
    {
        std::cout << vnum << " has grade " << grade << std::endl;
    }

    std::cout << std::endl;

    // Task 4: Print a single list of ID, name, grade (this
    //         is a "join" operation).

    std::cout << "Joined list: " << std::endl;
    for (const auto &[vnum, name] : student_names)
    {
        int grade = exam_grades.at(vnum);
        std::cout << vnum << " has name " << name << " and grade " << grade << std::endl;
    }

    // exam_grades["serkthydrtyyfo"];

    return 0;
}
