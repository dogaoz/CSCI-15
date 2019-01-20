//
// Mid2fall18.cpp
// Keith Mehl
// 11/28/18
// CSCI-15 code solutions for the second midterm
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// question 4
// C library abs() takes and returns integers, so isn't right to use here
// fabs() takes and returns doubles, and will work with floats or long doubles
// Or, you can test x - y < 0 and change the sign yourself, then test < 10^-9
// you could have a constant 1e-9, too
bool Equals( double x, double y )
{
    return ( fabs( x - y ) < 1e-9 );
}

// question 5
class POINT
{
private:
    double x, y;                     // coordinates
public:
    static const double Vertical;    // Vertical value
    double distance( POINT &b ); // non-ref is O.K. here
    // calculate and return the slope between two POINTS (delta x/delta y)
    double slope( POINT &b );    // or Vertical if delta x is near 0.0
    // print a POINT to an ostream in this form: ( x, y )
    friend ostream &operator <<( ostream &out, const POINT &p );
};

const double POINT::Vertical = 1e100;

double POINT::distance( POINT &b )
{
    return sqrt( ( (x - b.x) * (x - b.x) ) + ( (y - b.y) * (y - b.y) ) );
}

// you could have a constant for 1e10, too
double POINT::slope( POINT &b )
{
    return Equals( x, b.x ) ? Vertical : ( y - b.y ) / ( x - b.x );
}

ostream &operator <<( ostream &out, const POINT &p )
{
    out << "( " << p.x << ", " << p.y << " )" << flush;
    return out;
}

// question 6
class Quadrilateral
{
protected:  // not private - you want Square to see these
    POINT a, b, c, d;
public:
    friend ostream &operator <<( ostream &out, Quadrilateral &q );
    virtual double Perimeter( void );
};

ostream &operator <<( ostream &out, Quadrilateral &q )
{
    out << "I'm a Quadrilateral " << endl
        << q.a << ' ' << q.b << ' ' << q.c << ' ' << q.d << flush;
    return out;
}

double Quadrilateral::Perimeter( void )
{
    return a.distance( b ) + b.distance( c ) +
           c.distance( d ) + d.distance( a );
}

// Q6
class Square : public Quadrilateral
{
public:
    virtual double Perimeter( void );
    friend ostream &operator <<( ostream &out, Square &r );
};

double Square::Perimeter( void )
{
    return 4.0 * a.distance( b );
}

ostream &operator <<( ostream &out, Square &r )
{
    out << "I'm a Square\n";
    // cast to invoke Quadrilateral's friend operator << function
    out << dynamic_cast< Quadrilateral &>(r);
    return out;
}

// Q8
template <class T> Max( T a, T b )
{
    return a > b ? a : b;
}

int main()
{
    return 0;
}

