/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <stdexcept>
#include <string>

class Rectangle
{
public:
    //Task: Add a default constructor (which initializes the rectangle
    //      to have width = height = 0) and a parameterized constructor
    //      which takes a width and height (and verifies that they are
    //      valid).
    Rectangle()
    {
        std::cout << "Default constructor" << std::endl;
        width = height = 0;
    }

    Rectangle(double s)
    {
        std::cout << "square constructor" << std::endl;

        if (s < 0)
            throw std::runtime_error("Invalid size");

        width = height = s;

        area_ = s * s;
    }

    Rectangle(double w, double h)
    {
        std::cout << "WH constructor" << std::endl;

        if (w < 0 || h < 0)
            throw std::runtime_error("Invalid sizes");

        width = w;
        height = h;
        area_ = w * h;
    }

public:
    //Task: Add get_width and get_height functions which return the width
    //      and height of this rectangle
    double get_width()
    {
        return width;
    }

    void set_width(double w)
    {
        if (w < 0)
            throw std::runtime_error("w<0");
        width = w;
        area_ = height * width;
    }

    double get_height()
    {
        return height;
    }

    //Task: Add a get_area function which returns the area of this rectangle
    double area()
    {
        // return width * height;
        return area_;
    }

    //Task: Add a static member function create_unit_square which creates
    //      and returns a rectangle with width and height equal to 1
    static Rectangle create_unit_square()
    {
        Rectangle r{};
        r.width = 1;
        r.height = 1;
        r.area_ = 1;

        return r;
    }

private:
    double width{0};
    double height{0};
    double area_{0};
};

int main()
{
    Rectangle R{}; //This uses the default constructor

    std::cout << "R has width " << R.get_width() << std::endl;
    std::cout << "R has height " << R.get_height() << std::endl;
    std::cout << "R has area " << R.area() << std::endl;

    Rectangle R2{6, 10}; //This uses the parameterized constructor

    // R2.width = -6;
    // R2.set_width(-6);

    std::cout << "R2 has width " << R2.get_width() << std::endl;
    std::cout << "R2 has height " << R2.get_height() << std::endl;
    std::cout << "R2 has area " << R2.area() << std::endl;

    Rectangle R1{Rectangle::create_unit_square()};
    std::cout << "R1 has width " << R1.get_width() << std::endl;
    std::cout << "R1 has height " << R1.get_height() << std::endl;
    std::cout << "R1 has area " << R1.area() << std::endl;

    return 0;
}
