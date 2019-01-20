//
// mixedexpression.cpp
// Doga Ozkaracaabatlioglu
// October 17, 2018
// Assignment 4
//
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "mixedexpression.h"

using namespace std;

int main(int argc, char *argv[])
{
    char oper;
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output_mixedexp.txt");
    // Check for open failure.
    if (!fin)
    {
        cout << "Error while opening file" << endl;
        return -1;
    }
    if( !fout )
    {
        cout << "Output file open failed\n";
        return -2;
    }
    while (fin)
    {
        MixedExpression left_side, right_side;
        left_side.readMixedExp(fin);
        fin >> oper;
        right_side.readMixedExp(fin);
        left_side.printData(fout);
        fout << " " << oper << " " << flush;
        right_side.printData(fout);
        switch (oper)
        {
            case '+':
                left_side.add(right_side);
                break;
            case '-':
                left_side.subtract(right_side);
                break;
            case '*':
                left_side.multiply(right_side);
                break;
            case '/':
                left_side.divide(right_side);
                break;
            default:
                break;
        }
    fout << " = " << flush;
    left_side.printData(fout);
    fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

MixedExpression::MixedExpression(void)
{

}

MixedExpression MixedExpression::add( MixedExpression op )
{
    b = (op.c * (c*a+b))+ (c * (op.c*op.a+op.b));
    c = c * op.c;
    a = 0;
    reduce();
    return *this;
}
MixedExpression MixedExpression::subtract( MixedExpression op )
{
    b = op.c * (c*a+b) - c * (op.c*op.a+op.b);
    c = c * op.c;
    a = 0;
    reduce();
    return *this;
}
MixedExpression MixedExpression::multiply( MixedExpression op )
{
    b = op.c*c*a*op.a + c*a*op.b + op.c*b*op.a + b*op.b;
    c = c * op.c;
    a = 0;
    reduce();
    return *this;
}
MixedExpression MixedExpression::divide( MixedExpression op )
{
    b = (c*a+b) * op.c;
    c = c * (op.a*op.c + op.b);
    a = 0;
    reduce();
    return *this;
}
void MixedExpression::readMixedExp(istream &in)
{
    char temp,op1,op2;
    in >> temp; // parentheses
    in >> a;
    in >> op1; // plus or minus
    in >> b;
    in >> op2; // divide
    in >> c;
    in >> temp; // parentheses

    // Fix the negative
    if (op1 == '-')
    {
        a -= 1;

        b = c-b;

    }
    reduce();
}
int gcd(int a, int b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void MixedExpression::reduce() // validate
{
    // is it illegal? Make it zero
    if (c==0)
    {
        a = 0, b = 0, c = 1;
        return;
    }

    // Take apart th whole number out of the fraction
    while (b >= c) // b/c < 1
    {
        b -= c;
        a += 1;
    }

    // Reduce the fraction part
    int divisor = gcd(b,c);
    b = b / divisor;
    c = c / divisor;

    // Fix the negative
    while (b < 0 ^ c < 0)
    {
        if (c < 0)
        {
            b *= -1;
            c *= -1;
        }
        if (b < 0)
        {
            a -= 1;
            b *= -1;
            b = c-b;
        }
    }

}

void MixedExpression::printData( ostream &out )
{
    out << "( " << a << " + " << b << " / " << c << " )" << flush;
}
