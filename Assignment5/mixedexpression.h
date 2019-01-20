#ifndef MIXEDEXP_H
#define MIXEDEXP_H

#include <iostream>
using namespace std;

class MixedExpression
{
private:
    long a, b, c;
     void reduce();

public:
    MixedExpression();
    MixedExpression add(MixedExpression op);
    MixedExpression subtract(MixedExpression op);
    MixedExpression multiply(MixedExpression op);
    MixedExpression divide(MixedExpression op);
    void readMixedExp( istream &in );
    void printData( ostream &out );
    MixedExpression operator + (MixedExpression rhs);
    MixedExpression operator - (MixedExpression rhs);
    MixedExpression operator * (MixedExpression rhs);
    MixedExpression operator / (MixedExpression rhs);
    friend istream &operator >> ( istream &in, MixedExpression &op);
    friend ostream &operator << ( ostream &out, MixedExpression &op );

};
#endif
