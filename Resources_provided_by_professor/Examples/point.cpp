//
// point.cpp
//
// Keith Mehl
// 10/29/13
// Implementation of a simple Point class
//

#include <iostream>
#include <cmath>
using namespace std;
#include "point.h"

// print in format ( x, y )
ostream &operator << (ostream &out, Point &p )
{
   out << "( " << p._x << ", " << p._y << " )" << flush;
   return out;
}

// extract from format ( x, y )
istream &operator >> (istream &in, Point &p )
{
   char d;
   in >> d >> p._x >> d >> p._y >> d;
   return in;
}

Point::Point()
{
   _x = _y = 0.0;
}

Point::Point( double x, double y )
{
   _x = x;  // or, call SetAll() in here
   _y = y;
}

void Point::SetAll( double x, double y )
{
   _x = x;
   _y = y;
   return;
}

double Point::Distance( Point b )
{
    return sqrt( ( ( _x - b._x ) * ( _x - b._x ) ) +
                 ( ( _y - b._y ) * ( _y - b._y ) ) );
}
