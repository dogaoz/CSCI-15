//
// main.cpp
// Doga Ozkaracaabatlioglu
// November 6, 2018
// Assignment 5
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
