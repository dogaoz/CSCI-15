//
// member_type.cpp
//
// Keith Mehl
// April 2, 2008
// Illustrate :: scope resolution operator and typedef
//

#include <iostream>
using namespace std;

class TEST
{
public:
        // define a locally defined type not visible outside TEST
    typedef unsigned int UINT_TYPE;
    TEST() { t = 0u; }
    TEST( UINT_TYPE i ) { t = i; }
    UINT_TYPE get_val() { return t; }
    void set_val( UINT_TYPE i ) { t = i; }
    void set_val( TEST i ) { t = i.t; }
private:
    UINT_TYPE t;
};

int main()
{
    TEST::UINT_TYPE i = 2;  // comment out the TEST:: and watch what happens
    TEST x, y( i );
    cout << "i is " << i << ", x is " << x.get_val()
         << ", y is " << y.get_val() << endl;
    x.set_val( i );
    cout << "i is " << i << ", x is " << x.get_val()
         << ", y is " << y.get_val() << endl;
    y.set_val( 7u );  // u suffix means "unsigned"
    x.set_val( y );
    cout << "i is " << i << ", x is " << x.get_val()
         << ", y is " << y.get_val() << endl;
    return 0;
}

