#ifndef trapezoid_h
#define trapezoid_h

#include "quadrilateral.h"
class Trapezoid : public Quadrilateral
{
protected:
    void validate();
    void setDefault();
public:
    Trapezoid();
    Trapezoid(Point &a, Point &b, Point &c, Point &d);
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
    void print(ostream &out);
    #ifdef POLYMORPH
    virtual
    #endif
    void read(istream &in);
friend istream &operator >> (istream &in, Trapezoid &t);
friend ostream &operator << (ostream &out, Trapezoid &t);
};
#endif
