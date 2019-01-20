//
// mid1Fall2018.cpp
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#if 0
MoveHare() takes the position of a hare (on a 71-character race track
where track[0] is the starting gate and track[70] is the finish line),
and updates (NOTE: not returns) that position moved according to the
following rules:
40% chance of big hop to the right (6 places),
10% chance of little hop to the right (2 places),
20% chance of sleeping (no change),
10% chance of little slip to the left (1 place) and
20% chance of big slip to the left (5 places).
#endif // 0
// Question 1
void MoveHare( int &h )
{
    static int moves[10] = { 6, 6, 6, 6, 2, 0, 0, -1, -5, -5 };
    int mv = rand() % 10;
    h += moves[mv];
    if( h < 1 )
    {
        h = 1;
    }
    else if( h > 70 )
    {
        h = 70;
    }
    return;
}

//Question 2
int main2( int argc, char *argv[] )
{
    ifstream fin;
    ofstream fout;
    int seed;
    if( argc < 4 )
    {
        cout << "Usage: program inputfile outputfile seedrule" << endl;
        return -1;
    }
    seed = atoi( argv[3] );
    if( seed == 0 )
    {
        srand( time( nullptr ) );
    }
    else if( seed > 0 )
    {
        srand( seed );
    }
    fin.open( argv[1] );
    fout.open( argv[2] );
    if( !fin || !fout )
    {
        cout << "Error opening files!" << endl;
        return -2;
    }
    // Not part of exam question! Just for reference in example code
    cout << argv[0] << "\ninput file " << argv[1] << "\noutput file "
         << argv[2] << "\nseed rule " << argv[3] << endl;
    return 0;
}

// Question 3
char *StringCat1( char t[], char s[] )
{
    int i, j;
    for( i = 0; t[i]; i++ );
    for( j = 0; t[i] = s[j]; i++, j++ );
    return t;
}
char *StringCat2( char *t, char *s )
{
    int i = 0, j = 0;
    while( *( t + i ) )
    {
        i++;
    }
    while( *( t + i++ ) = *( s + j++ ) );
    return t;
}
char *StringCat3( char *t, char *s )
{
    char *p = t;
    while( *t )
    {
        t++;
    }
    while( *t++ = *s++ );
    return p;
}

// Question 4
int foo( int &a, int b )
{
    int c = a + b * 2;
    a = b + c;
    b /= 2;
    cout << a << ' ' << b << ' ' << c << endl;
    return a + b - c;
}

int main4()
{
    int a = 7, b = 3, c;
    c = foo( b, a );
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    b = foo( a, c );
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    return 0;
}

// Question 5
int PrintTokens( char *s )
{
    int numTokens = 0;
    char *p = strtok( s, " ,;." );
    while( p )
    {
        cout << p << endl;
        numTokens++;
        p = strtok( nullptr, " ,;." );
    }
    return numTokens;
}

int main( int argc, char *argv[] )
{
    int hare = 0;
    MoveHare( hare );
    cout << "hare position = " << hare << endl;
    MoveHare( hare );
    cout << "hare position = " << hare << endl;
    MoveHare( hare );
    cout << "hare position = " << hare << endl;
    MoveHare( hare );
    cout << "hare position = " << hare << endl;
    cout << "--------------------------" << endl;
    main2( argc, argv );
    cout << "--------------------------" << endl;
    char s1[100] = "cat", s2[100] = "dog";
    cout << "SC1 - " << StringCat1( s1, s2 );
    cout << "\nSC2 - " << StringCat2( s1, s2 );
    cout << "\nSC3 - " << StringCat3( s1, s2 );
    cout << endl;
    cout << "--------------------------" << endl;
    main4();
    cout << "--------------------------" << endl;
    char str[100] = "The quick brown fox jumps over a lazy dog";
    int tokens = 0;
    tokens = PrintTokens( str );
    cout << "There were " << tokens << " tokens" << endl;
    return 0;
}
#if 0
hare position = 6
hare position = 5
hare position = 7
hare position = 13
--------------------------
mid1Fall2018
input file in.txt
output file out.txt
seed rule 50
--------------------------
SC1 - catdog
SC2 - catdogdog
SC3 - catdogdogdog
--------------------------
24 3 17
a = 7 b = 24 c = 10
37 5 27
a = 37 b = 15 c = 10
--------------------------
The
quick
brown
fox
jumps
over
a
lazy
dog
There were 9 tokens
#endif // 0
