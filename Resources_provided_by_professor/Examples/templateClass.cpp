//
// templateClass.cpp
//
// Keith Mehl
// 11/12/15
// CSCI-15 example program
// Illustrate a simple template class
//

#include <iostream>
using namespace std;

template <class T> class NumberType
{
private:
    T val;
public:
    NumberType( T v ) { val = v; }
    bool operator > ( T rhs ) { return val > rhs.val; }
    void Set( T v ) { val = v; }
    T Get() { return val; }
    operator T() { return val; }
    void print( ostream &out ) { out << "In print() " << val << flush; }
    friend ostream &operator << ( ostream &out, T &rhs )
    {
        // rhs.print( out );
        out << "In operator << " << rhs.val << flush;
        return out;
    }
};

int main()
{
    NumberType<int> i(15);
    NumberType<double> d = 3.14159265358979;

    i.print( cout );
    d.print( cout );
    cout << "int type " << i;
    cout << "\ndouble type " << d << endl;
    int j = 5 + i;
    double x = 2.5 + d;
    cout << "j = " << j << " x = " << x << endl;
    return 0;
}
