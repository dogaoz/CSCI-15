//
// pair.cpp
//
// Example from Jonathan Traugott
// Illustrate the pair template class
//

#include <iostream>
#include <string>
#include "Pair.h"
using namespace std;
int main()
{
    Pair<int> p;
    cout << "p is " << p << endl;
    cout << "p._first is " << p.getFirst() << "" << endl;
    cout << "p._second is " << p.getSecond()  << endl;
    p.setFirst(100);
    cout << "p._first is now " << p.getFirst()  << endl;
    cout << "p is now " << p << endl;
    p.swap();
    cout << "after swap p is " << p << endl;
    Pair<string> q("Hello");
    Pair<string> r = q;
    cout << "q is " << q << endl;

    cout << "q._first is \"" << q.getFirst() << "\"" << endl;
    cout << "q._second is \"" << q.getSecond() << "\"" << endl;
    cout << "r is " << r << endl;
    cout << "q == r is evaluates to " << (q == r) << endl;
    cout << "q != r is evaluates to " << (q != r) << endl;
    q.setSecond("Goodbye");
    cout << "q.second is now \"" << q.getSecond() << "\"" << endl;
    cout << "q is " << q << endl;
    cout << "q == r is evaluates to " << (q == r) << endl;
    cout << "q != r is evaluates to " << (q != r) << endl;
    q.swap();
    cout << "After swap q is " << q << endl;
    return 0;
}
