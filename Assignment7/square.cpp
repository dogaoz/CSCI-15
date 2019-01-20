//
// square.cpp
//
// Doga Ozkaracaabatlioglu
// Nov 11, 2018
// Rectangle Class method definitions
//
#include "helper_functions.h"
#include "square.h"

Square::Square()
{
    setDefault();
}
void Square::setDefault()
{
    pointA.setAll(0,0);
    pointB.setAll(1,0);
    pointC.setAll(1,1);
    pointD.setAll(0,1);
}

Square::Square(Point &a, Point &b, Point &c, Point &d)
{
    setAll(a,b,c,d);
}

void Square::validate()
{
    double AB_distance = pointA.distance(pointB);
    double BC_distance = pointB.distance(pointC);
    double CD_distance = pointC.distance(pointD);
    double DA_distance = pointD.distance(pointA);

    if(Equals(AB_distance, BC_distance)
       && Equals(BC_distance, CD_distance)
       && Equals(CD_distance, DA_distance))
    {
        cout << "@@ SQUARE VALIDATED" << endl;
    }
    else
    {
        cout << "@@ ERROR WHILE VALIDATING SQUARE" << endl;
        cout << "+SQ+ Erroneous shape coordinates given below: " << endl;
        Square::print(cout);
        cout << endl << "+SQ+ Setting and printing default coordinates" << endl;
        Square::setDefault();
        Square::print(cout);
        cout << "+SQ+ Done." << endl << endl;
    }
}

double Square::Perimeter()
{
    return Parallelogram::Perimeter();
}

double Square::Area()
{
    double side = pointA.distance(pointB);
    return side * side;
}
void Square::print(ostream &out)
{
    out << "This is a Square" << endl;
    Rectangle::print(out);
}
void Square::read(istream &in)
{
    Rectangle::read(in);
    validate();
}
istream &operator >> (istream &in, Square &t)
{
    t.read(in);
    return in;
}

ostream &operator << (ostream &out, Square &t)
{
    t.print(out);
    return out;
}


