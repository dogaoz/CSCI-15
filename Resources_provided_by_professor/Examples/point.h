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
private:
   double _x, _y; // coordinates
public:
   Point();
   Point( double x, double y );
   void SetAll( double x, double y );
   double Distance( Point b );
};

#endif // POINT_H_INCLUDED

