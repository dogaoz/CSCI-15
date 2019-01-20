//
// main.cpp
//
// Matthew Gustafson, Doga Ozkaracaabatlioglu
// 11/7/2018
// Lab 07
// Class Inheritance
//
// Demonstrate inheritance using Employee's and Production Worker example
// classes.
//

#include <iostream>
#include <fstream>
#include "employee.h"
#include "productionworker.h"
using namespace std;

const int ARR_MAX = 7;

int main(int argc, char *argv[]){

    Employee employees[ARR_MAX];
    ProductionWorker pr_workers[ARR_MAX];
    int id = 0, date = 0, i = 0, shift = 0;
    double rate;
    string name;

    ifstream fin;

    if (argc < 4)
    {
        cout << "Usage: ./program employee_list.txt production_workers.txt"
             << " output.txt"
             << endl;
        return -1;
    }

    fin.open(argv[1]);
    if (!fin)
    {
        cout << "File open failed!" << endl;
        return -2;
    }

    while(fin)
    {
        fin >> name >> id >> date;
        employees[i].setAll(name,id,date);
        i++;
    }
    fin.close();

    i = 0;
    fin.open(argv[2]);
    if (!fin)
    {
        cout << "File open failed!" << endl;
        return -3;
    }

    while(fin)
    {
        fin >> name >> id >> date >> shift >> rate;
        pr_workers[i].setAll(name,id,date,shift,rate);
        i++;
    }
    fin.close();

    ofstream fout;
    fout.open(argv[3]);
    if (!fout)
    {
        cout << "File open failed!" << endl;
        return -3;
    }
    fout << "## Employees ##" << endl;
    for (i=0;i<ARR_MAX;i++)
    {
        fout << employees[i] << endl;
    }
    fout << "## Production Workers ##" << endl;
    for (i=0;i<ARR_MAX;i++)
    {
        fout << pr_workers[i] << endl;
    }


    fout << "## TESTING GETTERS FOR EMPLOYEE NO 0 ##" << endl;
    fout << "## Get ID: " << employees[0].getID() << endl;
    fout << "## Get Name: " << employees[0].getName() << endl;
    fout << "## Get Date: " << employees[0].getDate() << endl;
    fout << "## CHANGING ID ##" << endl;
    employees[0].setAll(employees[0].getName(), 4, employees[0].getDate());
    fout << "## Get ID: " << employees[0].getID() << endl;
    fout << "## Get Name: " << employees[0].getName() << endl;
    fout << "## Get Date: " << employees[0].getDate() << endl;


    fout << "## TESTING GETTERS FOR PRODUCTION WORKER NO 0 ##" << endl;
    fout << "## Get ID: " << pr_workers[0].getID() << endl;
    fout << "## Get Name: " << pr_workers[0].getName() << endl;
    fout << "## Get Date: " << pr_workers[0].getDate() << endl;
    fout << "## Get Rate: " << pr_workers[0].getRate() << endl;
    fout << "## Get Shift: " << pr_workers[0].getShift() << endl;
    fout << "## CHANGING RATE ##" << endl;
    pr_workers[0].setAll(pr_workers[0].getName(), pr_workers[0].getID(),
                        pr_workers[0].getDate(), pr_workers[0].getShift(), 90);
    fout << "## Get ID: " << pr_workers[0].getID() << endl;
    fout << "## Get Name: " << pr_workers[0].getName() << endl;
    fout << "## Get Date: " << pr_workers[0].getDate() << endl;
    fout << "## Get Rate: " << pr_workers[0].getRate() << endl;
    fout << "## Get Shift: " << pr_workers[0].getShift() << endl;

    fout.close();

    return 0;
}
