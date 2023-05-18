#pragma once

#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

namespace ariel
{
    class Point
    {
        double posX, posY;

    public:
        // constructor
        Point(double x, double y);
        Point();

        // distance between two points
        double distance(const Point &other) const;

        string print();

        Point moveTowards(const Point &src, const Point &dest, double distance);

        double getX() const;
        double getY() const;
        void setX(double value);
        void setY(double value);
        friend bool operator==(const Point &point1, const Point &point2);
    };

}
