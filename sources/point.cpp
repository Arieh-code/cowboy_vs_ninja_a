#include "point.hpp"

using namespace ariel;

Point::Point(double x, double y)
    : posX(x), posY(y)
{
}

double Point::getX() const
{
    return posX;
}

double Point::getY() const
{
    return posY;
}

double Point::distance(const Point &other) const
{
    return 0.0;
}

void Point::print()
{
    cout << "( " << posX << ", " << posY << " )" << endl;
}

Point Point::moveTowards(const Point &src, const Point &dest, double distance)
{
    // for now so the tests runs
    return Point(posX, posY);
}

bool operator==(const Point &point1, const Point &point2){
    return 1;
}
