//
// productionworker.cpp
//
// Matthew Gustafson
// 11/7/2018
// Lab 07
// Implementation of ProductionWorker class
//

#include <iostream>
#include <fstream>
#include <string>
#include "productionworker.h"
using namespace std;

// validate
void ProductionWorker::validate(){
    Employee::validate();
    if(_shift<0 || _shift>2){
        _shift = 0;          // 0 default
    }
    if(_rate<15.00){
        _rate = 15.00;       // min wage
    }
    return;
}

// constructors
ProductionWorker::ProductionWorker() : Employee(){
    _shift = 0;
    _rate = 15.00;
}

ProductionWorker::ProductionWorker(string name, int id, int date,
                                        int shift, double rate)
                                        : Employee(name, id, date){
    _shift = shift;
    _rate = rate;
    ProductionWorker::validate();
}

// mutators
void ProductionWorker::setAll(string name, int id, int date,
                                           int shift, double rate){
    Employee::setAll(name, id, date);
    _shift = shift;
    _rate = rate;
    ProductionWorker::validate();
}

// observers
int ProductionWorker::getShift(){
    return _shift;
}

double ProductionWorker::getRate(){
    return _rate;
}

// input/output and friend functions
void ProductionWorker::printProductionWorker(ostream &out){
    Employee::printEmployee(out);
    out << ", Shift: " << _shift << ", Rate: $" << _rate << flush;
    return;
}

void ProductionWorker::readProductionWorker(istream &in){
    // assumes proper formatting, ex:  Mary 255 20160528 0 15.25
    in >> _name >> _id >> _date >> _shift >> _rate;
    ProductionWorker::validate();
    return;
}

ostream &operator <<(ostream &out, ProductionWorker &p){
    p.printProductionWorker(out);
    return out;
}

istream &operator >>(istream &in, ProductionWorker &p){
    p.readProductionWorker(in);
    return in;
}

