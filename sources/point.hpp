#pragma once

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
        void setX(double value);
        void setY(double value);
        friend bool operator==(const Point &point1, const Point &point2);
    };

}
