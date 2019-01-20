#ifndef parallelogram_h
#define parallelogram_h

#include "trapezoid.h"
class Parallelogram : public Trapezoid
{
protected:
    void validate();
public:
    Parallelogram();
    Parallelogram(Point &a, Point &b, Point &c, Point &d);
    void setDefault();
    double Perimeter();
    double Area();
    void print(ostream &out);
    void read(istream &in);

friend istream &operator >> (istream &in, Parallelogram &pa);
friend ostream &operator << (ostream &out, Parallelogram &pa);
};

#endif // parallelogram_h
