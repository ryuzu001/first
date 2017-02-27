#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point()
    :xCoord(0.0), yCoord(0.0)
{
    xCoord = 0.0;
    yCoord = 0.0;
}

Point::Point(double x, double y)
    :xCoord(x),yCoord(y)
{xCoord = x;
    yCoord = y;
}

double Point::operator-(const Point &p) const{
    return sqrt(pow(p.xCoord - xCoord, 2) + pow(p.yCoord - yCoord, 2));
}
    
void Point::display() const{
cout << "(" << xCoord << "," << yCoord << ")";
}