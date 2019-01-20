//
// mixedexpression.cpp
// Doga Ozkaracaabatlioglu
// November 6, 2018
// Assignment 5
// Mixed Expression with operator methods
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
        fin >> left_side;
        fin >> oper;
        fin >> right_side;
        fout << left_side << flush;
        fout << " " << oper << " " << flush;
        fout << right_side << flush;
        switch (oper)
        {
            case '+':
                left_side = left_side + right_side;
                break;
            case '-':
                left_side = left_side - right_side;
                break;
            case '*':
                left_side = left_side * right_side;
                break;
            case '/':
                left_side = left_side / right_side;
                break;
            default:
                break;
        }
    fout << " = " << flush;
    fout << left_side << flush;
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
MixedExpression MixedExpression::operator + (MixedExpression rhs)
{
    this->add(rhs);
    return *this;
}
MixedExpression MixedExpression::operator - (MixedExpression rhs)
{
    this->subtract(rhs);
    return *this;
}
MixedExpression MixedExpression::operator * (MixedExpression rhs)
{
    this->multiply(rhs);
    return *this;
}
MixedExpression MixedExpression::operator / (MixedExpression rhs)
{
    this->divide(rhs);
    return *this;
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
    int divisor = b;
    int temp_c = c;
    while (temp_c != 0)
    {
    int t = temp_c;
    temp_c = divisor % temp_c;
    divisor = t;
    }
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
void MixedExpression::readMixedExp(istream &in)
{
    char temp,op1,op2;
    in >> temp >> a >> op1 >> b >> op2 >> c >> temp;
    reduce();
}

istream &operator >> (istream &in, MixedExpression &op)
{
    op.readMixedExp(in);
    return in;
}

void MixedExpression::printData( ostream &out )
{
    out << "( " << a << " + " << b << " / " << c << " )" << flush;
}

ostream &operator <<( ostream &out, MixedExpression &op )
{
    op.printData(out);
    return out;
}
