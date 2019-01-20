//
// circle.h
//
// Keith Mehl
// 10/28/08
// CSCI-15 example program
// Illustrate inheritance with a simple circle class
// A Circle "is a" Point with a radius
//

#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <iostream>
using std::ostream;

#include "point.h"

// Circle is publicly derived from Point
// everything in Point comes along into Circle automatically
// then we can add other features (the radius)
class Circle : public Point
{
private:
    double _r;      // radius
public:
    static const double PI; // = 3.14159265358979323846;
    // default and normal constructors
    Circle();
    Circle( double xVal, double yVal, double rVal );
    // mutator - set radius and set all
    void setR( double rVal );
    void setAll( double xVal, double yVal, double rVal );
    // observers - get radius and friend print function
    double getR( void );
    double getArea( void );
    double distance( Circle &b ); // return distance between self and b
    // friend to print
    friend ostream &operator <<( ostream &out, const Circle &c );
};

#endif // CIRCLE_H_INCLUDED

