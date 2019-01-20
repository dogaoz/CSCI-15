//
// rectangle.cpp
//
// Doga Ozkaracaabatlioglu
// Nov 11, 2018
// Rectangle Class method definitions
//
#include "helper_functions.h"
#include "rectangle.h"

Rectangle::Rectangle()
{
    setDefault();
}

void Rectangle::setDefault()
{
    pointA.setAll(0,0);
    pointB.setAll(2,0);
    pointC.setAll(2,1);
    pointD.setAll(0,1);
}

Rectangle::Rectangle(Point &a, Point &b, Point &c, Point &d)
{
    setAll(a,b,c,d);
}

void Rectangle::validate()
{
    if ( ( ((pointA.slope(pointB)*pointB.slope(pointC)) == -1
        && (pointB.slope(pointC)*pointC.slope(pointD)) == -1
        && (pointC.slope(pointD)*pointD.slope(pointA)) == -1
        && (pointD.slope(pointA)*pointA.slope(pointB)) == -1) )
            || pointA.slope(pointB) == Point::UNDEFINED_SLOPE
            || pointB.slope(pointC) == Point::UNDEFINED_SLOPE
            || pointC.slope(pointD) == Point::UNDEFINED_SLOPE
            || pointD.slope(pointA) == Point::UNDEFINED_SLOPE
            )
    {
        cout << "@@ RECTANGLE VALIDATED" << endl;
    }
    else
    {
        cout << "@@ ERROR WHILE VALIDATING RECTANGLE" << endl;
        cout << "+RE+ Erroneous shape coordinates given below: " << endl;
        Rectangle::print(cout);
        cout << endl << "+RE+ Setting and printing default coordinates" << endl;
        Rectangle::setDefault();
        Rectangle::print(cout);
        cout << "+RE+ Done." << endl << endl;

    }
}

double Rectangle::Perimeter()
{
    return Parallelogram::Perimeter();
}

double Rectangle::Area()
{
    return pointA.distance(pointB) * pointB.distance(pointC);
}
void Rectangle::print(ostream &out)
{
    out << "This is a Rectangle" << endl;
    Parallelogram::print(out);
}
void Rectangle::read(istream &in)
{
    Parallelogram::read(in);
    validate();
}
istream &operator >> (istream &in, Rectangle &t)
{
    t.read(in);
    return in;
}

ostream &operator << (ostream &out, Rectangle &t)
{
    t.print(out);
    return out;
}

