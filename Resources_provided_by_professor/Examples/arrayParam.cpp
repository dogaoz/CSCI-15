//
// arrayParam.cpp
//
// Keith Mehl
// 9/4/13
// Array parameter example program
//

#include <iostream>
using namespace std;

void foo( int a[][7], int rows )
{
   int i, j;
   for( i = 0; i < rows; i++ )
   {
      for( j = 0; j < 7; j++ )
      {
         a[i][j] = i*j;
         cout << a[i][j] << '\t';
      }
      cout << endl;
   }
   return;
}

int main()
{
   int a1[5][7] = {{0}}, a2[9][7] = {{0}};
   foo( a1, 5 );
   cout << endl;
   foo( a2, 9 );
   return 0;
}

