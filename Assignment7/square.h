#ifndef square_h
#define square_h

#include "rectangle.h"
class Square : public Rectangle
{
protected:
    void validate();
public:
    Square();
    Square(Point &a, Point &b, Point &c, Point &d);
    void setDefault();
    double Perimeter();
    double Area();
    void print(ostream &out);
    void read(istream &in);

friend istream &operator >> (istream &in, Square &sq);
friend ostream &operator << (ostream &out, Square &sq);
};

#endif //square_h

