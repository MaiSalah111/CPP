#include "Point.hpp"

static float TriangleArea(const Point p1, const Point p2, const Point p3) {
    float area = p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())
                + p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())
                + p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat());
    area = std::abs(area) * 0.5;
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float A = TriangleArea(a, b, c);
    float A1 = TriangleArea(a, b, point);
    float A2 = TriangleArea(a, c, point);
    float A3 = TriangleArea(b, c, point);
    if (A1 == 0 || A2 == 0 || A3 == 0)
        return false;
    float sum = A1 + A2 + A3;
    return sum == A;
}