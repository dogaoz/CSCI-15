//
// type-info.cpp
//
// Adapted from Cplusplus.com example for standard library typeinfo class
//
#include <iostream>
#include <typeinfo>
using namespace std;

struct Base {};
struct Derived : Base {};
struct Poly_Base
{
    virtual void Member() {}
};
struct Poly_Derived: Poly_Base { virtual void Member() {} };

int main()
{
    // built-in types:
    int i;
    int * pi;
    cout << "typeid(int) is: " << typeid(int).name() << endl;
    cout << "typeid(i)   is: " << typeid(i).name() << endl;
    cout << "typeid(pi)  is: " << typeid(pi).name() << endl;
    cout << "typeid(*pi) is: " << typeid(*pi).name() << endl << endl;

    // non-polymorphic types:
    Derived derived;
    Base* pbase = &derived;
    cout << "typeid(derived) is: " << typeid(derived).name() << endl;
    cout << "typeid(*pbase)  is: " << typeid(*pbase).name() << endl;
    cout << boolalpha << "same type? ";
    cout << ( typeid(derived)==typeid(*pbase) ) << endl << endl;

    // polymorphic types:
    Poly_Derived polyderived;
    Poly_Base* ppolybase = &polyderived;
    cout << "typeid(polyderived) is: " << typeid(polyderived).name() << endl;
    cout << "typeid(*ppolybase)  is: " << typeid(*ppolybase).name() << endl;
    cout << boolalpha << "same type? ";
    cout << ( typeid(polyderived)==typeid(*ppolybase) ) << endl;
    return 0;
}

