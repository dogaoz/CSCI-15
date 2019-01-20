//
// assignment1.cpp
// Doga Ozkaracaabatlioglu
// August 29, 2018
// Assignment 1
// Calculation
//

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


void ReadItem(ifstream &is)
{
    double a, b, c;
    is >> a;
    is >> b;
    is >> c;
    if (a != EOF || b != EOF || c != EOF)
    {

    }
    is.ignore();
}

//void PrintItem(MenuItem menuItem, ostream &os)
//{
    //os << menuItem.name << " -- $" << menuItem.price << endl;
//}

double get_positive_root(double a, double b, double c)
{
    return (-b + sqrt(b*b - 4.0*a*c)) / (2.0 * a);
}

double get_negative_root(double a, double b, double c)
{
    return (-b - sqrt(b*b - 4*a*c)) / (2 * a);
}

void printTable()
{


}
int main()
{

    ifstream fin;
    fin.open( "products.txt");
    // Check for open failure.
    if( !fin )
    {
       cout << "Input file open failed\n";
      return -2;
    }


    for (int i=1;i<10;i++)
    {
        cout << i <<" : " << flush;
    }
    fin.close();

    cout << get_positive_root(1.2, -2.3, 0.4) << '\n' << endl;

    cout << get_negative_root(1.2, -2.3, 0.4) << '\n' << endl;

    cout << get_positive_root(0, -2, 8.85) << '\n' << endl;

    cout << get_negative_root(0, -2, 8.85) << '\n' << endl;

    return 0;
}



