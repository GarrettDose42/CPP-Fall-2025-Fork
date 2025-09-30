#include <iostream>
#include <string>
#include <stdexcept>

/* Read a number from the user and return it */

int read_one_number()
{
    int value{};
    if (std::cin >> value)
    {
        //Value read successfully
        return value;
    }
    else
    {
        // std::runtime_error error{"Failed to read a number"};
        // throw error;

        throw std::runtime_error{"Failed to read a number"};
    }
}

int main()
{

    std::cout << "Enter a number: ";

    // int n{0};

    try
    {
        // n = read_one_number();

        int n{read_one_number()};
        std::cout << "You entered " << n << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Badness happend" << std::endl;
    }

    //Question: How can we detect cases where read_one_number failed?

    // std::cout << "You entered " << n << std::endl;
    std::cout << "End of main" << std::endl;
    return 0;
}