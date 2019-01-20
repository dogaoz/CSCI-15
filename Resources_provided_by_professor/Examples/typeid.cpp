//
// typeid.cpp
//
// Keith Mehl
// 11/3/09
// CSCI-15 example program
// Illustrate C++ standard library typeid class
// show two different types and their type names
// type names are implementation-specific
// On Quincy, RTTI must be enabled for this to compile and run,
// and you should also enable exception handling to use typeid
//

#include <iostream>
#include <typeinfo>  // for typeid class
using namespace std;

int main ()
{
    int *a, b;  // a is an int *, b is an int
    a = 0;      // this coerces 0 from int to int* -- Use NULL/nullptr instead!
    b = 0;
    if (typeid(a) != typeid(b))
    {
        cout << "a and b are of different types:\n";
    }
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    return 0;
}

