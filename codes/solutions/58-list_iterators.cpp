/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <list>
#include <stdexcept>

/* list_sum_elementwise(L1, L2)
   Given two lists L1 and L2 of equal size, return a new list
   whose elements are the sum of the corresponding elements of L1 and L2.
   For example, with
     L1:   6   10   17
     L2: 116  187  111
   the result will be
         122  197  128

   If the two input lists do not have equal size, throw an instance
   of std::invalid_argument.
*/

//
//vec1[i]+vec2[i]

std::list<int> list_sum_elementwise(std::list<int> const &L1, std::list<int> const &L2)
{
    if (L1.size() != L2.size())
    {
        throw std::invalid_argument{"L1 and L2 should have same size"};
    }

    std::list<int> res;

    // std::list<int>::const_iterator i1 = L1.begin();
    auto i1 = L1.begin();
    auto i2 = L2.begin();

    //for/while
    while (i1 != L1.end())
    // while (i2 != L2.end())
    // for (; i1 != L1.end();)
    {
        const int v1 = *i1;
        const int v2 = *i2;

        res.push_back(v1 + v2);

        ++i1;
        ++i2;
    }

    // for (auto i1 = L1.begin(), i2 = L2.begin(); i1 != L1.end(); ++i1, ++i2)
    // {
    //     res.push_back(*i1 + *i2);
    // }

    return res;
}

int main()
{
    std::list<int> A{10, 20, 30, 40};
    std::list<int> B{6, 10, 17, 187};

    auto result = list_sum_elementwise(A, B);

    std::cout << "Result: ";
    for (auto x : result)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
