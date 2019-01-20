//
// polyTypeid.cpp
// Keith Mehl
// 11/3/09
// CSCI-15 example program
// using typeid with polymorphic class objects
// illustrate virtual destructor
//

#include <iostream>
#include <typeinfo>
using namespace std;

// Absolute minimal class definitions, with virtual destructor
class CBase
{
public:
    virtual void f() {}
    virtual ~CBase() { cout << "in CBase destructor" << endl; }
};
class CDerived : public CBase
{
public:
    virtual void f() {}
    virtual ~CDerived() { cout << "in CDerived destructor" << endl; }
};

int main ()
{
    CBase* a = new CBase;
    CBase* b = new CDerived;
    cout << "a is: " << typeid(a).name() << '\n';
    cout << "b is: " << typeid(b).name() << '\n';
    cout << "*a is: " << typeid(*a).name() << '\n';
    cout << "*b is: " << typeid(*b).name() << '\n';
    cout << "Deleting a" << endl;
    delete a;
    cout << "Deleting b" << endl;
    delete b;
    return 0;
}

