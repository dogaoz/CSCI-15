//
// employee.cpp
//
// Matthew Gustafson
// 11/7/2018
// Lab 07
// Implementation of Employee class
//

#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"
using namespace std;

// validate
void Employee::validate(){
    if(_id<0){
        _id = 0;
    }
    if(_date<0){
        _date = 20000101;
    }
    return;
}

// constructors
Employee::Employee(){
    _name = "NONE";          // default name is "NONE"
    _id = 0;                 // default id is 0, proper id is 1 on
    _date = 20000101;        // default date is Jan 1, 2000
}

Employee::Employee(string name, int id, int date){
    _name = name;
    _id = id;
    _date = date;
    validate();
}

// mutators
void Employee::setAll(string name, int id, int date){
    _name = name;
    _id = id;
    _date = date;
    validate();
}

// observers
string Employee::getName(){
    return _name;
}

int Employee::getID(){
    return _id;
}

int Employee::getDate(){
    return _date;
}

// input/output and friend functions
void Employee::printEmployee(ostream &out){
    out << "Name: " << _name << ", ID: " << _id << ", Hire date: " << _date
        << flush;
        return;
}

void Employee::readEmployee(istream &in){
    // assumes proper formatting, ex:  Mary 255 20160528
    in >> _name >> _id >> _date;
    validate();
    return;
}

ostream &operator <<(ostream &out, Employee &e){
    e.printEmployee(out);
    return out;
}

istream &operator >>(istream &in, Employee &e){
    e.readEmployee(in);
    return in;
}

