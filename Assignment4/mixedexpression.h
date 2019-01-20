#ifndef MIXEDEXP_H
#define MIXEDEXP_H
using namespace std;

class MixedExpression
{
private:
    long a, b, c;

public:
    MixedExpression();
    MixedExpression add(MixedExpression op);
    MixedExpression subtract(MixedExpression op);
    MixedExpression multiply(MixedExpression op);
    MixedExpression divide(MixedExpression op);
    void readMixedExp( istream &in );
    void printData( ostream &out );
    void reduce();

};
#endif
