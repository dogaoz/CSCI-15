//
// circle.cpp
//
// Keith Mehl
// 10/29/13
// implement a simple Circle class by aggregation on Point
//

#include <iostream>
#include <cmath>
#include "circle.h"
using namespace std;
const double PI = 3.14159265358979;

// print ( x, y ), r radius
ostream &operator <<( ostream &out, Circle &c )
{
   out << c.center << ", r " << c.radius << flush;
   return out;
}

// read point as ( x, y ) , radius
istream &operator >>( istream &in, Circle &c )
{
   char d;
   in >> c.center >> d >> c.radius;
   return in;
}

Circle::Circle() : center() // initializer list
{
   radius = 1.0;
}
// normal constructor with : initializer list
// : center( x, y ) invokes center's constructor
Circle::Circle( double x, double y, double r ) : center( x, y )
{
   radius = r > 0 ? r : 1.0;
}
// normal constructor with : initializer list
// : center( c ) assigns Point c to field center
Circle::Circle( Point c, double r ) : center( c )
{
    // center = c;
    radius = r > 0 ? r : 1.0;
}

void Circle::SetAll( double x, double y, double r )
{
   center.SetAll( x, y );
   radius = r > 0 ? r : 1.0;
   return;
}

double Circle::Area()
{
   return PI * radius * radius;
}

double Circle::Circumference()
{
   return 2.0 * PI * radius;
}

double Circle::Distance( Circle b )
{
    return center.Distance( b.center );
}

