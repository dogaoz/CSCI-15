//
// point.h
//
// Keith Mehl
// 10/29/13
// A simple Point class for an aggregation example
//
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
using namespace std;

class Point
{
   friend ostream &operator << (ostream &out, Point &p );
   friend istream &operator >> (istream &in, Point &p );
protected:
   double _x, _y; // coordinates
public:
   static const double UNDEFINED_SLOPE;
   Point();
   Point( double x, double y );
   double getX(void)  const;
   double getY(void)  const;
   void setAll( double x, double y );
   double distance( Point &b );
   double slope( Point &b );
};

#endif // POINT_H_INCLUDED

