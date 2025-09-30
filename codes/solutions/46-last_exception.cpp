#include <iostream>
#include <vector>

int last(const std::vector<int> &input)
{
    /* Question: What should we do if the input vector
                 has no elements at all? */

    if (input.size() <= 0)
    {
        throw std::invalid_argument{"This is broken for empty vector!"};
        // return -1;
    }

    return input.at(input.size() - 1);

    // try
    // {
    //     // return input.at(input.size() - 100);
    //     // return input.at(input.size() - 1);
    // }
    // catch (const std::out_of_range &)
    // {
    //     throw std::invalid_argument{"This is broken for empty vector!"};
    // }

    // return input[input.size() - 1];
}

int main()
{
    std::vector<int> W{6, 10, 17};
    // std::vector<int> W{};
    auto z{last(W)};
    std::cout << "z: " << z << std::endl;
    return 0;
}
