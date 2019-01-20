//
// quarilateral.cpp
//
// Doga Ozkaracaabatlioglu
// Nov 10, 2018
// Quadrilateral Class method definitions
//
#include "helper_functions.h"
#include "quadrilateral.h"

Quadrilateral::Quadrilateral()
{
    setDefault();
}
void Quadrilateral::setDefault()
{
    pointA.setAll(0,0);
    pointB.setAll(3,0);
    pointC.setAll(2,1);
    pointD.setAll(1,2);
}

Quadrilateral::Quadrilateral(Point &a, Point &b, Point &c, Point &d)
{
    // Normal Constructor
    setAll(a,b,c,d);
}


void Quadrilateral::validate()
{
    int error = 0;
    // Validate if it is convex(all internal angles < 180)
    if ( !(pointA.getX() < pointB.getX()) )  // A to B (goes right)
    {
        error += 1;
    }
    if ( !(pointB.getY() < pointC.getY()) ) // B to C (goes up)
    {
        error += 10;
    }
    if ( !(pointC.getX() > pointD.getX()) ) // C to D (goes left)
    {
        error += 100;
    }
    if ( !(pointD.getY() > pointA.getY()) ) // D to A (goes down)
    {
        error += 1000;
    }

    if (error > 0)
    {
        cout << "@@ ERROR WHILE VALIDATING QUADRILATERAL" << endl;
        cout << "+QU+ Erroneous shape coordinates given below: " << endl;
        Quadrilateral::print(cout);
        cout << endl << "+QU+ Setting and printing default coordinates" << endl;
        Quadrilateral::setDefault();
        Quadrilateral::print(cout);
        cout << "+QU+ Done." << endl << endl;
    }
    else
    {
        cout << "@@ QUADRILATERAL VALIDATED" << endl;
    }
}

Point Quadrilateral::getA()
{
    return pointA;
}
Point Quadrilateral::getB()
{
    return pointB;
}
Point Quadrilateral::getC()
{
    return pointC;
}
Point Quadrilateral::getD()
{
    return pointD;
}
double Quadrilateral::Perimeter()
{
    double perimeter = 0.0;
    perimeter += pointA.distance(pointB);
    perimeter += pointB.distance(pointC);
    perimeter += pointC.distance(pointD);
    perimeter += pointD.distance(pointA);
    return perimeter;
}
double Quadrilateral::Area()
{
    //Heron's formula
    double sides_tri1[3], sides_tri2[3];
    double tri_area1, tri_area2, s;

    sides_tri1[0] = pointA.distance(pointB);
    sides_tri1[1] = pointB.distance(pointD);
    sides_tri1[2] = pointD.distance(pointA);

    s = (sides_tri1[0] + sides_tri1[1] + sides_tri1[2])/2;
    tri_area1 = sqrt(s*(s-sides_tri1[0])*(s-sides_tri1[1])*(s-sides_tri1[2]));

    sides_tri2[0] = pointB.distance(pointC);
    sides_tri2[1] = pointC.distance(pointD);
    sides_tri2[2] = pointD.distance(pointB);

    s = (sides_tri2[0] + sides_tri2[1] + sides_tri2[2])/2;
    tri_area2 = sqrt(s*(s-sides_tri2[0])*(s-sides_tri2[1])*(s-sides_tri2[2]));

    return tri_area1 + tri_area2;
}
void Quadrilateral::setAll(Point &a, Point &b, Point &c, Point &d)
{
    pointA = a;
    pointB = b;
    pointC = c;
    pointD = d;
    validate();
    return;
}
void Quadrilateral::read(istream &is)
{
    char bye;
    double cs[8];
    is >> bye >> cs[0] >> bye >> cs[1] >> bye
       >> bye >> cs[2] >> bye >> cs[3] >> bye
       >> bye >> cs[4] >> bye >> cs[5] >> bye
       >> bye >> cs[6] >> bye >> cs[7] >> bye;
    Point a(cs[0],cs[1]), b(cs[2],cs[3]), c(cs[4],cs[5]), d(cs[6],cs[7]);
    setAll(a, b, c, d);
}
void Quadrilateral::print(ostream &out)
{
    out << "This is a quadrilateral" << endl
        << pointA << endl << pointB << endl << pointC << endl << pointD << endl;
}
ostream &operator << (ostream &out, Quadrilateral &q)
{
    q.print(out);
    return out;
}
istream &operator >> (istream &in, Quadrilateral &q)
{
    q.read(in);
    return in;
}
