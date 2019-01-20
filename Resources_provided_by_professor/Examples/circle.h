//
// circle.h
//
// Keith Mehl
// 10/29/13
// create a circle that "has-a" point (the center) and a radius
// Illustrate class aggregation (using a class object as a class member
// with the other class defined outside the enclosing class)
//

#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include "Point.h"
#include <iostream>
using namespace std;

class Circle
{
friend ostream &operator <<( ostream &out, Circle &c );
friend istream &operator >>( istream &in, Circle &c );
private:
   Point center;   // Circle has-a Point (e.g., as a member)
   double radius;  // and a radius
public:
   Circle();
   Circle( double x, double y, double r );
   Circle( Point c, double r );
   void SetAll( double x, double y, double r );
   double Area();
   double Circumference();
   double Distance( Circle b );
};

#endif // CIRCLE_H_INCLUDED

