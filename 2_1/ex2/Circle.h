#include<iostream>
#include "Point.h"
using namespace std;
class Circle{
    private:
    Point centerPoint;
    double radius;
    public:
    void display();
    Circle();
    Circle(Point, double);
    double operator-(Circle);
};