//
// friends.cpp
// Keith Mehl
// 7/31/2000
//
// Illustrate simple friend function
//
#include <iostream.h>

class MyInt
{
   friend void changeMyInt( MyInt &m, int i );
private:
   int myInt;
public:
   void setMyInt( int i );
   int  getMyInt( void );
};

// changeMyInt is a friend function, so it can "reach into"
// the class and modify its private data member myInt.
void changeMyInt( MyInt &m, int i )
{
   m.myInt = i;
}

// these are member functions, so they have access to myInt
void MyInt::setMyInt( int i )
{
   myInt = i;
}
int MyInt::getMyInt( void )
{
   return myInt;
}

// now some code to drive it all
int main( void )
{
   MyInt i;

   i.setMyInt( 10 );
   cout << "The value of MyInt i is " << i.getMyInt() << endl;
   changeMyInt( i, 25 );
   cout << "The value of MyInt i is " << i.getMyInt() << endl;
   return 0;
}

#if 0 // output
The value of MyInt i is 10
The value of MyInt i is 25
#endif