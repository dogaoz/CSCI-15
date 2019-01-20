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
    Date a(1938, 10, 9);
    Date b;
    b.SetAll(1920, 10, 10);

   // cout << "a: Year is: " << a.GetYear() << endl;
   // cout << "a: Month is: " << a.GetMonth() << endl;
   // cout << "a: Day is: " << a.GetDay() << endl;
   // cout << "b: Year is: " << b.GetYear() << endl;
   // cout << "b: Month is: " << b.GetMonth() << endl;
   // cout << "b: Day is: " << b.GetDay() << endl;

    cout << "Day difference between " << flush;
    a.print(2,cout);
    cout << " and " << flush;
    b.print(2,cout);
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
    static char *month_names[12] = {"January", "February", "March", "April",
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

    static int num_days_in_month[12] = {31, 28, 31, 30, 31, 30,
                                        31, 31, 30, 31, 30, 31};

    // Validate february if leap year
    if(year % 4 == 0 || year % 100 == 0 || year % 400 == 0 )
        num_days_in_month[1] = 29;
    else
        num_days_in_month[1] = 28;

    //cout << "RETURNING " << num_days_in_month << " for " << year << endl;
    return num_days_in_month;
}
int Date::GetDayDifference(Date d)
{
    Date a = *this;
    Date b = d;

    if(a._y > b._y)// Reverse if the parameter's date is before the current date
    {
        Date t = a;
        a = b;
        b = t;
    }

    int min_year = MIN(a._y,b._y);
    int max_year = MAX(a._y,b._y);

    int total_days = 0;
    int *num_days_in_month = a.GetDayTableFromAYear();
    cout << "0: " << a._y << " - " << b._y << endl;

    // This doesn't work if "&& a._m != b._m" part stays in the code
    // in case where the month is same (9 October 1938 and 10 October 1920)
    // and calculates wrong but instructions told me to do it this way.
    // So...
    if (a._y != b._y && a._m != b._m)
    {
        total_days += num_days_in_month[a._m-1] - a._d;
        cout << endl;
        cout << "1: month - day in = " << total_days << endl;


        for(int i = a._m+1;i <= 12;i++)
        {
            total_days += num_days_in_month[i-1];
            cout << "2: " << num_days_in_month[i-1] << endl;
        }
            cout << "3: " << min_year << " - " << max_year << endl;

        if (a._y != b._y)
        {
            cout << "3: " << min_year << " - " << max_year << endl;
            min_year++;
            while (min_year < max_year)
            {
                int days_to_be_added;
                days_to_be_added = 365;
                if (GetDayTableFromAYear(min_year)[1] == 29)
                    days_to_be_added++;

                cout << "3.1 : " << days_to_be_added << " for " << min_year << endl;
                total_days += days_to_be_added;
                min_year++;
            }
             cout << "4: " << total_days << endl;
        }

    }
    num_days_in_month = b.GetDayTableFromAYear();
    for(int i = 0;i < b._m;i++)
    {
        if (i == b._m-1)
        {
            cout << "5: month no " << i << " adds " << b._d << endl;
            cout << total_days << " + " << b._d << endl;
            total_days += b._d;
        }
        else
        {
             cout << "5: month no " << i << " adds " << num_days_in_month[i] << endl;
             cout << total_days << " + " << num_days_in_month[i] << endl;
             total_days += num_days_in_month[i];
        }


    }

    return total_days;
}

