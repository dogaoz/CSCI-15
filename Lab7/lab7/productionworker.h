//
// productionworker.h
//
// Matthew Gustafson
// 11/7/2018
// Lab 07
// Header file for ProductionWorker class
//

#ifndef PRODUCTIONWORKER_H_INCLUDED
#define PRODUCTIONWORKER_H_INCLUDED

#include "employee.h"
using namespace std;

class ProductionWorker : public Employee{
protected:
    int _shift;
    double _rate;
    void validate();
public:
    // constructors
    ProductionWorker();
    ProductionWorker(string name, int id, int date, int shift, double rate);
    // mutators
    void setAll(string name, int id, int date, int shift,
                             double rate);
    // observers
    int getShift();
    double getRate();
    void printProductionWorker(ostream &out);
    void readProductionWorker(istream &in);
friend ostream &operator <<(ostream &out, ProductionWorker &p);
friend istream &operator >>(istream &in, ProductionWorker &p);
};

#endif // PRODUCTIONWORKER_H_INCLUDED
