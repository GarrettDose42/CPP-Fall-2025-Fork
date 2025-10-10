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

double get_area(Rectangle R)
{
    return R.width * R.height;
}

int main()
{

    Rectangle R{6, 10};

    std::cout << "Area of R: " << get_area(R) << std::endl;

    return 0;
}
