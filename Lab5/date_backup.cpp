//
// date.cpp
// Doga Ozkaracaabatlioglu
// October 23, 2018
// Lab 5
// Date class and demonstration
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "date.h"

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int main(int argc, char *argv[])
{
    Date a(1997, 9, 2);

    a.print(2,cout);
    cout << endl;

    Date b;

    b.SetAll(2002, 5, 4);

    b.print(2,cout);
    cout << endl;

   // cout << "a: Year is: " << a.GetYear() << endl;
   // cout << "a: Month is: " << a.GetMonth() << endl;
   // cout << "a: Day is: " << a.GetDay() << endl;
   // cout << "b: Year is: " << b.GetYear() << endl;
   // cout << "b: Month is: " << b.GetMonth() << endl;
   // cout << "b: Day is: " << b.GetDay() << endl;

    cout << "Day difference between a.GetDayDifference(b): " << flush;
    cout << a.GetDayDifference(b) << endl;
    cout << "Day difference between b.GetDayDifference(a): " << flush;
    cout << b.GetDayDifference(a) << endl;


    return 0;
}

Date::Date()
{
    _y=1, _m=1, _d=1;
    return;
}
Date::Date(int y, int m, int d)
{

    SetAll(y,m,d);
}
void Date::SetAll(int y, int m, int d)
{
    int err = 0;
    if (y >= 0 && y <= 3000)
        _y = y;
    else
        err = 1;

    int *num_days_in_month = GetDayTableFromAYear();
    if (m > 0 && m <= 12)
        _m = m;
    else
        err = 1;

    if (d > 0 && d <= num_days_in_month[m])
        _d = d;
    else
        err = 1;

    if (err)
    {
        _y = 1, _m = 1, _d = 1;
    }

    return;
}
int Date::GetYear()
{
    return _y;
}
int Date::GetMonth()
{
    return _m;
}
int Date::GetDay()
{
    return _d;
}

void Date::print(int option, ostream &out)
{
    static char* month_names[12] = {"January", "February", "March", "April",
                                     "May", "June", "July", "August",
                                     "September", "October", "November",
                                     "December"};

    switch (option)
    {
    case 0:
        out << _m << "/" << _d << "/" << _y << flush;
        break;
    case 1:
        out << month_names[_m-1] << " " << _d << ", " << _y << flush;
        break;
    case 2:
        out << _d << " " << month_names[_m-1] << " " << _y << flush;
        break;
    default:
        break;
    }
}
int* Date::GetDayTableFromAYear(int y)
{
    int year;
    if (y==0)
        year = _y;
    else
        year = y;

    static int num_days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Validate february if leap year
    if(year % 4 == 0 || year % 100 == 0 || year % 400 == 0 )
        num_days_in_month[1] = 29;
    else
        num_days_in_month[1] = 28;

    return num_days_in_month;
}
int Date::GetDayDifference(Date b)
{
    Date a = *this;

    int min_year = MIN(_y,b._y);
    int max_year = MAX(_y,b._y);

    int total_days = 0;
    int *num_days_in_month = b.GetDayTableFromAYear();

    if (_y != b._y && _m != b._m)
    {
        total_days += num_days_in_month[_m-1] - _d;
        cout << endl;
        cout << "1: month - day in = " << total_days << endl;


        for(int i = _m+1;i <= 12;i++)
        {
            total_days += num_days_in_month[i-1];
            cout << "2: " << num_days_in_month[i-1] << endl;
        }

        if (_y != b._y)
        {
            cout << "3: " << min_year << " - " << max_year << endl;
            min_year++;
            while (min_year < max_year)
            {
                int days_to_be_added;
                days_to_be_added= 365;
                if (GetDayTableFromAYear(min_year)[1] == 29)
                    days_to_be_added++;

                cout << "3.1 : " << days_to_be_added << " for " << min_year << endl;
                total_days += days_to_be_added;
                min_year++;
            }
             cout << "4: " << total_days << endl;
        }

    }

    for(int i = 0;i < b._m;i++)
    {
        if (i == b._m-1)
        {
            cout << "5: month no " << i << " adds " <<b._d << endl;
            total_days += b._d;
        }
        else
        {
             cout << "5: month no " << i << " adds " << num_days_in_month[i] << endl;
             total_days += num_days_in_month[b._m];
        }


    }

    return total_days;
}

