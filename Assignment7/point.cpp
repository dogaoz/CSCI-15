//
// point.cpp
//
// Keith Mehl
// 10/28/08
// CSCI-15 Example program
// A simple point class
//

#include <iostream>
#include <cmath>
using std::ostream;
using std::flush;
using std::sqrt;

#include "point.h"

const double Point::UNDEFINED_SLOPE = 1e100;
// default constructor
Point::Point()
{
    _x = _y = 0.0;
}

// normal constructor
Point::Point( double xVal, double yVal )
{
    setAll( xVal, yVal );
}

// manipulator - set x and y
void Point::setAll( double xVal, double yVal )
{
    _x = xVal;
    _y = yVal;
    return;
}

// observers - get value of x and y
double Point::getX( void ) const
{
    return _x;
}

double Point::getY( void ) const
{
    return _y;
}

// return distance between self and b
double Point::distance( Point &b )
{
    return sqrt( (_x - b._x) * (_x - b._x) +
                 (_y - b._y) * (_y - b._y) );
}

double Point::slope(Point &b)
{
    if ((_x - b._x) == 0)
    {
        return UNDEFINED_SLOPE;
    }
    else
    {
        return (_y - b._y)/(_x - b._x); 
    }
}

// observer - print in format ( x, y )
ostream &operator <<( ostream &out, Point &p )
{
    out << "( " << p.getX() << ", " << p.getY() << " )" << flush;
    return out;
}
