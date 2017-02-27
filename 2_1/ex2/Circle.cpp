#include "Circle.h"

void Circle::display(){
    centerPoint.display();
    cout << "," << radius;
}
Circle::Circle(){
    Point p;
    centerPoint =p;
    radius = 0;
}
Circle::Circle(Point p1, double rad){
    centerPoint = p1;
    radius = rad;
}
double Circle::operator-(Circle c){
    return centerPoint - c.centerPoint;
}