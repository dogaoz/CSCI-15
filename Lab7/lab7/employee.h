//
// employee.h
//
// Matthew Gustafson
// 11/7/2018
// Lab 07
// Header file for Employee class
//

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee{
protected:
    string _name;
    int _id, _date;
    void validate();
public:
    // constructors
    Employee();
    Employee(string name, int id, int date);
    // mutators
    void setAll(string name, int id, int date);
    // observers
    string getName();
    int getID();
    int getDate();
    void printEmployee(ostream &out);
    void readEmployee(istream &in);
friend ostream &operator <<(ostream &out, Employee &e);
friend istream &operator >>(istream &in, Employee &e);
};

#endif // EMPLOYEE_H_INCLUDED
