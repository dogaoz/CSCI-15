//
// trapezoid.cpp
//
// Doga Ozkaracaabatlioglu
// Nov 10, 2018
// Trapezoid Class method definitions
//
#include "helper_functions.h"
#include "trapezoid.h"

Trapezoid::Trapezoid()
{
    Trapezoid::setDefault();
}
void Trapezoid::setDefault()
{
    pointA.setAll(0,0);
    pointB.setAll(2,2);
    pointC.setAll(2,3);
    pointD.setAll(0,5);
}

Trapezoid::Trapezoid(Point &a, Point &b, Point &c, Point &d)
{
    setAll(a,b,c,d);
}

void Trapezoid::validate()
{
    // FLOATING POING TYPES IN C++ ARE APPROXIMATIONS, NOT EXACT VALUES.
    // WRITE AN EQUALS() FUNCTION THAT TAKES 2 DOUBLES AND RETURNS TRUE IF
    // THEY ARE CLOSE ENOUGH TO THE SAME VALUE, I.E. WITHIN 10^-9 OF EACH OTHER

    // |AB| and |DC| is parallel (top and bottom)
    if (Equals(pointA.getY(),pointB.getY())
        && Equals(pointC.getY(),pointD.getY()) )
    {
        cout << "@@ TRAPEZOID VALIDATED" << endl;
    }
    // or left and right side
    else if (Equals(pointA.getX(),pointD.getX())
             && Equals(pointB.getX(), pointC.getX()) )
    {
        cout << "@@ TRAPEZOID VALIDATED" << endl;
    }
    else
    {
        cout << "@@ ERROR WHILE VALIDATING TRAPEZOID" << endl;
        cout << "+TR+ Erroneous shape coordinates given below: " << endl;
        Trapezoid::print(cout);
        cout << endl << "+TR+ Setting and printing default coordinates" << endl;
        Trapezoid::setDefault();
        Trapezoid::print(cout);
        cout << "+TR+ Done." << endl << endl;

    }

}

double Trapezoid::Perimeter()
{
    return Quadrilateral::Perimeter();
}

double Trapezoid::Area()
{
    // Height point
    // that is perpendicular to base
    // and at the end of the base line
    int height = 1; // ??????
    return ((pointA.distance(pointB) + pointC.distance(pointD)) / 2) * height;
}
void Trapezoid::print(ostream &out)
{
    out << "This is a Trapezoid " << endl;
    Quadrilateral::print(out);
}
void Trapezoid::read(istream &in)
{
    Quadrilateral::read(in);
    validate();
}
istream &operator >> (istream &in, Trapezoid &t)
{
    t.read(in);
    return in;
}

ostream &operator << (ostream &out, Trapezoid &t)
{
    t.print(out);
    return out;
}
