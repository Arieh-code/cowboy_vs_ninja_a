#include "Point.hpp"


using namespace ariel;

Point::Point(double posX, double posY)
    : posX(posX), posY(posY)
{
}

Point::Point()
    : posX(0), posY(0)
{}

double Point::getX() const
{
    return posX;
}

double Point::getY() const
{
    return posY;
}

void Point::setX(double x)
{
    posX = x;
}

void Point::setY(double y)
{
    posY = y;
}

double Point::distance(const Point &other) const
{
    double dx = other.posX - posX;
    double dy = other.posY - posY;
    return std::sqrt(dx * dx + dy * dy);
}

string Point::print()
{
    stringstream finalPrint;
    finalPrint << "(" << posX << ", " << posY << ")";
    return finalPrint.str();
}

Point Point::moveTowards(const Point &src, const Point &dest, double distance)
{
    if (src.distance(dest) <= distance)
    {
        return dest;
    }

    double ratio = distance / src.distance(dest);

    double newX = src.posX + (dest.posX - src.posX) * ratio;
    double newY = src.posY + (dest.posY - src.posY) * ratio;
    return Point(newX, newY);
}

bool ariel::operator==(const Point &point1, const Point &point2)
{
    return point1.getX() == point2.getX() && point1.getY() == point2.getY();
}
