//
// stringFtns.cpp
//
// Keith Mehl
// 9/11/11
// CSCI-15 Example program
// Illustrate using pointers to access arrays by duplicating
// the functionality of some of the <cstring> library functions.
// This is just to illustrate pointer use with arrays.
//
#include <iostream>
using namespace std;

// clone strcpy()
// copy s into t, return s
char *stringcpy( char *t, char *s )
{
    char *ct = t;         // copy the target to return
    while( *t++ = *s++ ); // copy until character copied is '\0' (empty body)
    return ct;            // return saved copy of target
}

// clone strcat()
// concatenate s onto end of t, return resulting string
char *stringcat( char *t, char *s )
{
    char *ct = t;         // copy target to return
    while( *t )           // find NUL at the of t
    {
         t++;
    }
    while( *t++ = *s++ ); // concatenate s including NUL
    return ct;
}

// clone strcmp()
// compare two strings.  return >0 if s > t, 0 if s == t, <0 if s < t.
// comparison is lexicograpic, e.g., per the ASCII character values

int stringcmp( char *s, char *t )
{
    // while not off end of either string and the strings match
    while( *s && *s == *t )
    {
        s++;  // advance to next character in the strings
        t++;
    }
    return *s - *t;  // *s - *t will be >0, 0 or <0 per rule above
}

// this one isn't a clone of a string library function
// reverse a C-string "in-place", e.g., without using a buffer for a copy
// return the reversed string
char *stringrev( char *s )
{
    char *cs = s, *t = s; // copy to return, spare to find end
    while( *t )           // scan to end of s
    {
        t++;
    }
    t--;                   // back up from NUL to last character
    while( s < t )         // until pointer cross (why not s != t ?)
    {
        char tmp = *s;     // swap elements
        *s = *t;
        *t = tmp;
        s++;               // advance pointers
        t--;
    }
    return cs;            // and return the string
}

int main()
{
    bool more = true;
    char ch;
    char s1[100] = "", s2[100] = "", s3[200] = "";
    int res;
    while( more )
    {
        cout << "Enter a string\n" << flush;
        cin.getline( s1, 99, '\n' );
        cout << "Enter another string" << endl;
        cin.getline( s2, 99, '\n' );
        res = stringcmp( s1, s2 );
        if( res > 0 )
        {
            cout << '<' << s1 << "> is greater than <" << s2 << '>' << endl;
        }
        else if( !res ) // res == 0
        {
            cout << '<' << s1 << "> is the same as <" << s2 << '>' << endl;
        }
        else // no need to test, must be < 0
        {
            cout << '<' << s1 << "> is less than <" << s2 << '>' << endl;
        }

        stringcpy( s3, s1 );
        stringcat( s3, s2 );
        cout << "concatenated : <" << s3 << '>' << endl;

        stringcpy( s3, stringrev( s1 ) );
        cout << "s1 reversed is <" << s1 << '>' << endl;
        cout << "the new s3 is  <" << s3 << '>' << endl;

        cout << "\nMore? (y/n) " << flush;
        cin  >> ch;
        more = ( ch == 'y' || ch == 'Y' );
        cin.ignore( 100, '\n');  // needed after >> before another getline()
    }
    return 0;
}

