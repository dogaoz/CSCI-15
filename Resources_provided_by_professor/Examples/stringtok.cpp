//
// stringtok.cpp
// Keith Mehl
// Aug. 24, 2008
// CSCI-15 example program
// write a clone of strtok() from the C-string library
// without using any C-string library functions
//

#include <iostream>
using namespace std;

// return true if the character c is in the string s, including '\0'
bool IsIn( char c, char *s )
{
   // sanity check - saves having to test this in stringtok() itself
   if( !s )
   {
      return false;
   }
   while( *s && *s != c )
   {
      s++;
   }
   return *s == c;  // true if found, else false
}

// clone of strtok(), with identical functionality
char *stringtok( char *s, char *d )
{
   // will return p, q is next char, e is last of string
   static char *p = NULL, *q = NULL, *e = NULL;
   if( s == NULL )    // continue with prior string?
   {
      if( p == NULL ) // handle no prior string, either.
      {
         return p;
      }
      p = q + 1;  // start p at next character after '\0' end-of-token
   }
   else // start new string
   {
        // point p to s, e to the end of string (NUL)
      for( p = e = s; *e != '\0'; e++ );
   }
   while( p <= e && IsIn( *p, d ) )  // skip all leading delimiters
   {
      p++;
   }
   if( p >= e )  // off end of original string?
   {
      p = NULL;
   }
   else          // otherwise, we have a token
   {
      q = p + 1; // so look for a trailing delimiter
      while( q <= e && !IsIn( *q, d ) )  // advance q to first delimiter
      {
         q++;
      }
      *q = '\0'; // overwrite delimiter with NUL character
   }
   return p;  // token or NULL if no more tokens
}

int main()
{
   char s[1000] =
        "Here is a simple.,!@#$%\" test string with a bunch of delimiters",
        d[] = " .,;~`!@#$%^&*()_-+={[}]|\\\":<>?/\t";
   char *p;
   p = stringtok( s, d );
   while( p != NULL )
   {
      cout << p << endl;
      p = stringtok( NULL, d );
   }
   cout << "Enter a string to parse\n" << flush;
   cin.getline( s, 999, '\n' );
   p = stringtok( s, d );
   while( p != NULL )
   {
      cout << p << endl;
      p = stringtok( NULL, d );
   }
   return 0;
}


