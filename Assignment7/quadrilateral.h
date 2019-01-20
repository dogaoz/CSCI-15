#ifndef quadrilateral_h
#define quadrilateral_h

#include <cmath>
#include "point.h"
#include "helper_functions.h"
class Quadrilateral
{
protected:
    Point pointA, pointB, pointC, pointD;
    void validate();
    void setDefault();
public:
    Quadrilateral();
    Quadrilateral(Point &a, Point &b, Point &c, Point &d);
    Point getA();
    Point getB();
    Point getC();
    Point getD();
    void setAll(Point &a, Point &b, Point &c, Point &d);
    #ifdef POLYMORPH
    virtual
    #endif
    double Perimeter();
    #ifdef POLYMORPH
    virtual
    #endif
    double Area();
    #ifdef POLYMORPH
    virtual
    #endif
    void read(istream &is);
    #ifdef POLYMORPH
    virtual
    #endif
    void print(ostream &out);
friend istream &operator >> (istream &in, Quadrilateral &q);
friend ostream &operator << (ostream &out, Quadrilateral &q);
};
#endif // quadrilateral_h

