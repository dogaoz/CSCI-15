//
// parallelogram.cpp
//
// Doga Ozkaracaabatlioglu
// Nov 11, 2018
// Parallelogram Class method definitions
//
#include "helper_functions.h"
#include "parallelogram.h"

Parallelogram::Parallelogram()
{
    setDefault();
}
void Parallelogram::setDefault()
{
    pointA.setAll(0,0);
    pointB.setAll(3,2);
    pointC.setAll(3,5);
    pointD.setAll(0,3);
}
Parallelogram::Parallelogram(Point &a, Point &b, Point &c, Point &d)
{
    setAll(a,b,c,d);
}

void Parallelogram::validate()
{
    // FLOATING POING TYPES IN C++ ARE APPROXIMATIONS, NOT EXACT VALUES.
    // WRITE AN EQUALS() FUNCTION THAT TAKES 2 DOUBLES AND RETURNS TRUE IF
    // THEY ARE CLOSE ENOUGH TO THE SAME VALUE, I.E. WITHIN 10^-9 OF EACH OTHER

    // |AB| and |DC| is parallel (top and bottom)
    // and |AD| and |BC| (left and right side)
    if (Equals(pointA.getY(),pointB.getY())
        && Equals(pointC.getY(),pointD.getY())
        && Equals(pointA.getX(),pointD.getX())
        && Equals(pointB.getX(), pointC.getX()) )
    {
        cout << "@@ PARALLELOGRAM VALIDATED" << endl;
    }
    else
    {
        cout << "@@ ERROR WHILE VALIDATING PARALLELOGRAM" << endl;
        cout << "+PA+ Erroneous shape coordinates given below: " << endl;
        Parallelogram::print(cout);
        cout << endl << "+PA+ Setting and printing default coordinates" << endl;
        Parallelogram::setDefault();
        Parallelogram::print(cout);
        cout << "+PA+ Done." << endl << endl;

    }
}

double Parallelogram::Perimeter()
{
    return Trapezoid::Perimeter();
}

double Parallelogram::Area()
{
    return pointA.distance(pointB) * pointB.distance(pointC);
}
void Parallelogram::print(ostream &out)
{
    out << "This is a Parallelogram" << endl;
    Trapezoid::print(out);
}
void Parallelogram::read(istream &in)
{
    Trapezoid::read(in);
    validate();
}
istream &operator >> (istream &in, Parallelogram &t)
{
    t.read(in);
    return in;
}

ostream &operator << (ostream &out, Parallelogram &t)
{
    t.print(out);
    return out;
}
