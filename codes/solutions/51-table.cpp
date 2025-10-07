/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <vector>

/*python
from numpy import *

from numpy import array, abs


Eigen::MatrixXd

*/

//The "using" directive defines a new type (similar to typedef in C)
//Note that type definitions are scoped (so a using directive inside a function
//will only be visible from inside that function).

using Table = const std::vector<std::vector<int>>;

using namespace std;

void print_table(const Table &T)
{
    vector<double> test{};
}

Table duplicate_table(const Table &T)
{
    return Table{};
}

int main()
{
    using std::cout;
    using std::vector;

    vector<double> test{};
    vector<bool> test1{};

    // std::string blah{};
    // cout << blah.at(10) << std::endl;

    //Create table T of integer values with 3 rows and 5 columns.
    //Notice that the elements in the initializer for T
    //are initializers for one-dimensional vectors.
    //Note that "jagged" tables are possible (rows are not required to have the same size)
    Table T{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}};

    //Print the table with for-each loops
    // TO DO
    //auto = std::vector<int>
    for (const auto &r : T)
    {
        for (const auto &v : r)
        {
            cout << v << " ";
        }
        cout << std::endl;
    }

    cout << std::endl;

    //Print the table with a traditional indexing loop
    // TO DO
    // for (int i{0}; i < T.size(); ++i)
    // {
    //     for (int j{0}; j < T.at(i).size(); ++j)
    //     {
    //         // cout << T.at(i).at(j) << " ";
    //         cout << T[i][j] << " ";
    //     }

    //     cout << std::endl;
    // }

    for (int i{0}; i < T.size(); ++i)
    {
        const auto &r = T.at(i);
        for (int j{0}; j < r.size(); ++j)
        {
            cout << r.at(j) << " ";
        }

        cout << std::endl;
    }

    return 0;
}