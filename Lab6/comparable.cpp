//
// comparable.cpp
//
// Cole Steinmetz, Doga Ozkaracaabatlioglu
// 11/01/18
// CS15 Lab 6
// Template Functions
// 

#include <iostream>
using namespace std;

// Template Functions
template < typename T > T abs_val( T &a )
{
    return a < 0 ? -a : a;
}
template < typename T > T find_min( T &a, T &b )
{
    return (a < b) ? a : b;
}
template < typename T > T find_max( T &a, T &b )
{
     return (a > b) ? a : b;
}
template < typename T > T find_min( T &a, T &b, T &c )
{
    T t = find_min(a,b);
    return find_min(t,c);
}
template < typename T > T find_max( T &a, T &b, T &c )
{
     T t = find_max(a,b);
     return find_max(t,c);
}

// Comparable Class
class Comparable
{
private:
    double _a;
public:
    Comparable();
    Comparable(double a);
    Comparable lesser_than(Comparable rhs);
    Comparable greater_than(Comparable rhs);
    Comparable operator <(Comparable rhs);
    Comparable operator >(Comparable rhs);
};

Comparable::Comparable(void)
{
    _a = 0;
}

Comparable::Comparable(double a)
{
    _a = a;
}

Comparable Comparable::lesser_than(Comparable rhs)
{
    return find_min(_a, rhs._a);
}
Comparable Comparable::greater_than(Comparable rhs)
{
    return find_max(_a, rhs._a);
}

Comparable Comparable::operator <(Comparable rhs)
{
    return lesser_than(rhs);
}

Comparable Comparable::operator >(Comparable rhs)
{
    return greater_than(rhs);
}

int main()
{
    // 3 different data types with 3 different values.
    char ch1 ='H', ch2 = 'B', ch3 = 'a';
    int num1 = 28, num2 = 33, num3 = -2;
    double d1 = 2.2, d2 = -1.1, d3 = 5.2;

    // Start Comparing two like-data types
    // Char data types
    cout << "Compare two char data types:" << flush;
    cout << "  ch1 = " << ch1 << "  " << "ch2 = " << ch2 << endl;
    cout << "absolute value of ch1: " << abs_val(ch1) << endl;
    cout << "absolute value of ch2: " << abs_val(ch2) << endl;
    cout << find_min(ch1, ch2) << " is smaller of the two chars" << endl;
    cout << find_max(ch1, ch2) << " is bigger of the two chars" << endl;
    cout << "NOW! lets add a third char to the mix!\n" << "ch3 = ";
    cout << ch3 << " which has an absolute value of " << abs_val(ch3) << endl;
    cout << find_min(ch1, ch2, ch3) << " is the smallest among";
    cout << " the three data types" << endl;
    cout << find_max(ch1, ch2, ch3) << " is the biggest among";
    cout << " the three data types" << endl << endl;
    cout << endl;
    // int data types
    cout << "Compare two int data types:" << flush;
    cout << " num1 = " << num1 << "  " << "num2 = " << num2 << endl;
    cout << "absolute value of num1: " << abs_val(num1) << endl;
    cout << "absolute value of num2: " << abs_val(num2) << endl;
    cout << find_min(num1, num2) << " is smaller of the two ints" << endl;
    cout << find_max(num1, num2) << " is bigger of the two ints" << endl;
    cout << "NOW! lets add a third int to the mix!\n";
    cout << "num3 = " << num3 << " which has an absolute value of ";
    cout << abs_val(num3) << endl;
    cout << find_min(num1, num2, num3) << " is the smallest among";
    cout << " the three data types" << endl;
    cout << find_max(num1, num2, num3) << " is the biggest among";
    cout << " the three data types" << endl;
    cout << endl;
    // double data types
    cout << "Compare two double data types:" << flush;
    cout << "  d1 = " << d1 << "  " << "d2 = " << d2 << endl;
    cout << "absolute value of d1: " << abs_val(d1) << endl;
    cout << "absolute value of d2: " << abs_val(d2) << endl;
    cout << find_min(d1, d2) << " is smaller of the two doubles" << endl;
    cout << find_max(d1, d2) << " is bigger of the two doubles" << endl;
    cout << "NOW! lets add a third double to the mix!\n" << "d3 = ";
    cout << d3 << " which has an absolute value of " << abs_val(d3) << endl;
    cout << find_min(d1, d2, d3) << " is the smallest among";
    cout << " the three data types" << endl;
    cout << find_max(d1, d2, d3) << " is the biggest among";
    cout << " the three data types" << endl;
    cout << endl;

    return 0;
}
