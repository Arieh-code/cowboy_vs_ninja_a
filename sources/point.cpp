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

double Point::Distance(const Point &other) const
{
    return 0;
}

void Point::print()
{
    cout << "( " << x << ", " << y << " )" << endl;
}

Point Point::moveTowards(const Point &src, const Point &dest, double distance)
{
    // for now so the tests runs
    return Point(posX, posY);
}
