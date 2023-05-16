#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
using namespace std;

namespace ariel
{
    class Point
    {
        double posX, posY;

    public:
        // constructor
        Point(double x, double y);

        // distance between two points
        double distance(const Point &other) const;

        void print();

        Point moveTowards(const Point &src, const Point &dest, double distance);

        double getX() const;

        double getY() const;
    };

}

#endif // POINT_HPP