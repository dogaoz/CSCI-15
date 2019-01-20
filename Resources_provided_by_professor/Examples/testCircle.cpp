//
// testCircle.cpp
//
// Keith Mehl
// 10/29/13
// test the Circle class and, by aggregation, the Point class
//

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "point.h"
#include "circle.h"

int main()
{
   ifstream fin( "..\\circles.txt" ); // fix these names for your own system...
   ofstream fout( "..\\circleOut.txt" );
   if( !fin || !fout )
   {
      cout << "Error opening files!" << endl;
      exit( -1 );
   }
   Point p( 3.5, 4.5 );
   Circle c( p, 3.5 );
   cout << "c directly " << c << ", area = " << c.Area()
        << ", circumference = " << c.Circumference() << endl;
   Circle c1, c2( 2.5, 3.25, 4.0 );
   cout << "Print c1 and c2 directly\n" << c1 << " <--> " << c2 << endl;
   cout << "c1 area = " << c1.Area() << ", circumference = "
        << c1.Circumference() << endl;
   cout << "c2 area = " << c2.Area() << ", circumference = "
        << c2.Circumference() << endl;
   cout << "Distance c1 to c2 " << c1.Distance( c2 ) << endl;

   fin >> c1;
   while( !fin.eof() )
   {
      fout << "c1 area = " << c1.Area() << ", circumference = "
           << c1.Circumference() << endl;
      fin >> c1;
   }
   fin.close();
   fout.close();
   return 0;
}

