/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <string>
#include <iostream>
#include <stdexcept>

int F(int x)
{
    int bla{5};
    float haha{3.2};
    std::string foo{"hello"};

    if (x < 0)
    {
        throw bla;
    }
    if (x == 42)
    {
        throw haha;
    }
    if (x > 100)
        throw foo;

    return 6;
}

int main()
{
    int y{1000};

    try
    {
        y = F(42);
    }
    catch (const int value)
    {
        std::cout << "caught (int) " << value << std::endl;
    }
    catch (const std::string &value)
    {
        std::cout << "caught (string) " << value << std::endl;
    }
    catch (...)
    {
        std::cout << "we got it!!!! (probably wrong)" << std::endl;
    }

    std::cout << "y = " << y << std::endl;

    return 0;
}