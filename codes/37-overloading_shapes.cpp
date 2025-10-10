/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>

struct Rectangle
{
    double width{0};
    double height{0};
};

struct Triangle
{
    double base{0};
    double height{0};
};

double get_rectangle_area(Rectangle R)
{
    return R.width * R.height;
}

double get_triangle_area(Triangle T)
{
    return T.base * T.height / 2.0;
}

int main()
{
    Rectangle R{6, 10};
    std::cout << "Area of R: " << get_rectangle_area(R) << std::endl;

    Triangle T{17, 2};
    std::cout << "Area of T: " << get_triangle_area(T) << std::endl;

    return 0;
}
