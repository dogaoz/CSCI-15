#ifndef rectangle_h
#define rectangle_h

#include "parallelogram.h"
class Rectangle : public Parallelogram
{
protected:
    void validate();
public:
    Rectangle();
    Rectangle(Point &a, Point &b, Point &c, Point &d);
    void setDefault();
    double Perimeter();
    double Area();
    void print(ostream &out);
    void read(istream &in);

friend istream &operator >> (istream &in, Rectangle &re);
friend ostream &operator << (ostream &out, Rectangle &re);

};

#endif //rectangle_h
