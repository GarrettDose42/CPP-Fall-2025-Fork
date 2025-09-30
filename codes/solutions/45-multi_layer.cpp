/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <stdexcept>

int F(int x)
{
    std::cout << "Inside F " << x << std::endl;
    try
    {
        if (x > 10)
        {
            throw std::runtime_error{"Something bad happened."};
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "caugth (RE) inside F" << std::endl;
        try
        {
            throw std::out_of_range{"this is getting really messy!"};
        }
        catch (int ex)
        {
        }
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "caugth (OOR) inside F" << std::endl;
    }

    std::cout << "end of F, returning  " << 10 * x << std::endl;
    return x * 10;
}

int G(int y)
{
    std::cout << "Inside G " << y << std::endl;
    int result{0};
    try
    {
        while (y < 100)
        {
            // try
            // {
            result += F(y);
            // }
            // catch (const std::runtime_error &e)
            // {
            //     std::cout << "Caugth in G" << std::endl;
            // }
            y = 2 * y;
        }
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Caugth in G" << std::endl;
        throw std::runtime_error{"Only partially handled!"};
    }
    std::cout << "End of G, returning " << result << std::endl;
    return result;
}

int main()
{

    int y{999};
    try
    {
        y = G(6);
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "O_o" << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << ":D" << std::endl;
    }

    std::cout << "y is " << y << std::endl;

    return 0;
}
