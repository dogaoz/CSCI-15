#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;
#include "quadrilateral.h"
#include "trapezoid.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "square.h"

int main(int argc, char *argv[])
{
    if (system("CLS")) system("clear");

    ifstream fin;
    fin.open("input.txt");

    if (!fin)
    {
        cout << "Error: File couldn't be opened!" << endl;
    }

    Quadrilateral q;
    Trapezoid tr;
    Parallelogram p;
    Rectangle re;
    Square s;
    while (fin)
    {
        char t;
        fin >> t;
        switch (t)
        {
        case 'Q':
            cout << "@ A QUADRILATERAL IS BEING PROCESSED" << endl;
            fin >> q;
            cout << q;
            cout << "Perimeter: " << q.Perimeter() << endl
                 << "Area: " << q.Area() << endl;
            break;
        case 'T':
            cout << "@ A TRAPEZOID IS BEING PROCESSED" << endl;
            fin >> tr;
            cout << tr;
            cout << "Perimeter: " << tr.Perimeter() << endl
                 << "Area: " << tr.Area() << endl;
            break;
        case 'P':
            cout << "@ A PARALLELOGRAM IS BEING PROCESSED" << endl;
            fin >> p;
            cout << p;
            cout << "Perimeter: " << p.Perimeter() << endl
                 << "Area: " << p.Area() << endl;
            break;
        case 'R':
            cout << "@ A RECTANGLE IS BEING PROCESSED" << endl;
            fin >> re;
            cout << re;
            cout << "Perimeter: " << re.Perimeter() << endl
                 << "Area: " << re.Area() << endl;
            break;
        case 'S':
            cout << "@ A SQUARE IS BEING PROCESSED" << endl;
            fin >> s;
            cout << s;
            cout << "Perimeter: " << s.Perimeter() << endl
                 << "Area: " << s.Area() << endl;
            break;
        }

        cout << "#####################################################" << endl
             << "#####################################################" << endl
             << "#####################################################" << endl;
    }


    return 0;
}
