/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <stdexcept>
#include <set>

class Point
{
public:
    Point() : x{0}, y{0}
    {
    }
    Point(double x_val, double y_val) : x{x_val}, y{y_val}
    {
    }
    double get_x() const
    {
        return x;
    }
    double get_y() const
    {
        return y;
    }

private:
    double x, y;
};

/* Add an operator here */
// bool is_p1_less_than_p2(const Point &p1, const Point &p2)
bool operator<(const Point &p1, const Point &p2)
{
    if (p1.get_x() == p2.get_x())
    {
        return p1.get_y() < p2.get_y();
        // return false;
    }

    return p1.get_x() < p2.get_x();
}

int main()
{

    Point P{6, 17};
    Point Q{6, 10};
    Point R{1, -8};
    Point S{-3, -5};

    std::set<Point> point_set;

    //In order for .insert to work, there must be a < operator
    //defined for the element type.
    point_set.insert(P);
    point_set.insert(Q);
    point_set.insert(R);
    point_set.insert(S);

    for (auto pt : point_set)
    {
        std::cout << "(" << pt.get_x() << ", " << pt.get_y() << ") ";
    }
    std::cout << std::endl;

    Point search_point1{6, 10};
    Point search_point2{111, 116};
    if (point_set.contains(search_point1))
    {
        std::cout << "Found (6,10) in the set." << std::endl;
    }
    else
    {
        std::cout << "Did not find (6,10) in the set." << std::endl;
    }

    if (point_set.contains(search_point2))
    {
        std::cout << "Found (111,116) in the set." << std::endl;
    }
    else
    {
        std::cout << "Did not find (111,116) in the set." << std::endl;
    }
    return 0;
}
