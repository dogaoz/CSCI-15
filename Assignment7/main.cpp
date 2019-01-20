//
// main.cpp
//
// Doga Ozkaracaabatlioglu
// November 20, 2018
// Assignment 7 - Polymorphism
// Uses Virtual keyword to use polymorphism to access derived class methods
// instead of base class methods
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;
// Polymorphism is defined in helper_functions.h to activate it.
#include "quadrilateral.h"
#include "trapezoid.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "square.h"

void printFromReference(Quadrilateral &q)
{
     cout << q << endl << "Perimeter: " << q.Perimeter() << endl
          << "Area: " << q.Area() << endl;
}

void printFromPointer(Quadrilateral *q)
{
     cout << *q << endl << "Perimeter: " << q->Perimeter() << endl
          << "Area: " << q->Area() << endl;
}

int main(int argc, char *argv[])
{

    Quadrilateral *qs[5];

    Quadrilateral q;
    Trapezoid t;
    Parallelogram p;
    Rectangle r;
    Square s;

    qs[0] = &q;
    qs[1] = &t;
    qs[2] = &p;
    qs[3] = &r;
    qs[4] = &s;

    cout << "@@@@@@ Accessing the object by object name\n";
    cout << q << endl << "Perimeter: " << q.Perimeter() << endl << "Area: "
         << q.Area() << endl << t << endl << "Perimeter: " << t.Perimeter()
         << endl << "Area: " << t.Area() << endl << p << endl << "Perimeter: "
         << p.Perimeter() << endl << "Area: " << p.Area() << endl << r << endl
         << "Perimeter: " << r.Perimeter() << endl << "Area: " << r.Area()
         << endl << s << endl << "Perimeter: " << s.Perimeter() << endl
         << "Area: " << s.Area() << endl;

    cout << "@@@@@@ Accessing the object by object pointer\n";
    for (int i=0; i<5;i++)
        printFromPointer(qs[i]);
    cout << "@@@@@@ Accessing the object by object reference\n";
    for (int i=0; i<5;i++)
        printFromReference(*qs[i]);

    return 0;
}



