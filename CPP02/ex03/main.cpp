#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

// Declare the bsp function
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);
    Point point1(5.0f, 5.0f); // Inside the triangle
    Point point2(10.0f, 10.0f); // Outside the triangle
    Point point3(0.0f, 0.0f); // On the vertex
    Point point4(5.0f, 0.0f); // On the edge
   

    if (bsp(a, b, c, point1)) {
        std::cout << "Point (5, 5) is inside the triangle" << std::endl;
    } else {
        std::cout << "Point (5, 5) is outside the triangle" << std::endl;
    }

    if (bsp(a, b, c, point2)) {
        std::cout << "Point (10, 10) is inside the triangle" << std::endl;
    } else {
        std::cout << "Point (10, 10) is outside the triangle" << std::endl;
    }

    if (bsp(a, b, c, point3)) {
        std::cout << "Point (0, 0) is on vertex" << std::endl;
    } else {
        std::cout << "Point (0, 0) is not on vertex" << std::endl;
    }

    if (bsp(a, b, c, point4)) {
        std::cout << "Point (5, 0) is on edge" << std::endl;
    } else {
        std::cout << "Point (5, 0) is not on edge" << std::endl;
    }

    return (0);
}