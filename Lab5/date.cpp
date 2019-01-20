//
// date.cpp
// Doga Ozkaracaabatlioglu
// October 23, 2018
// Lab 5
// Date class and demonstration
//

#include <iostream>
#include <fstream>
#include "date.h"

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    fin.open("date_list.txt");
    fout.open("date_test_output.txt");
    int y[2],m[2],d[2];
    while(fin)
    {
        fin >> y[0];
        fin >> m[0];
        fin >> d[0];
        fin >> y[1];
        fin >> m[1];
        fin >> d[1];
        fout << "Data from file: " << y[0] << " " << m[0] << " " << d[0] << " "
                                   << y[1] << " " << m[1] << " " << d[1]
                                   << endl;
        fout << "With Constructor: " << endl;
        Date a(y[0],m[0],d[0]);
        a.print(0,fout);
        fout << endl;
        a.print(1,fout);
        fout << endl;
        a.print(2,fout);
        fout << endl;
        fout << "With SetAll: " << endl;
        Date b;
        b.SetAll(y[1],m[1],d[1]);
        b.print(0,fout);
        fout << endl;
        b.print(1,fout);
        fout << endl;
        b.print(2,fout);
        fout << endl;
        fout << "(A) Year: " << a.GetYear() << " Month: " << a.GetMonth()
            << " Day: " << a.GetDay() << endl;
        fout << "(B) Year: " << a.GetYear() << " Month: " << a.GetMonth()
            << " Day: " << a.GetDay() << endl;
        fout << "Day difference between " << flush;
        a.print(2,fout);
        fout << " and " << flush;
        b.print(2,fout);
        fout << endl;
        fout << a.GetDayDifference(b) << endl;
        fout << "# With parameters reversed #" << endl;
        fout << b.GetDayDifference(a) << endl;
        fout << "## END OF TWO DATES ##"<< endl;
    }
    fin.close();
    fout.close();
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

    // Reverse if the parameter's date is before the current date
    if(a._y > b._y)
    {
        Date t = a;
        a = b;
        b = t;
    }

    int min_year = MIN(a._y,b._y);
    int max_year = MAX(a._y,b._y);

    int total_days = 0;
    int *num_days_in_month = a.GetDayTableFromAYear();

    // If the dates are not in the same month and year...
    //
    // This doesn't work if "&& a._m != b._m" part stays in the code
    // in case where the month is same (9 October 1938 and 10 October 1920)
    // and calculates wrong but instructions told me to do it this way.
    // So...
    if (a._y != b._y && a._m != b._m)
    {

        // Get the number of days up to the end of this month
        total_days += num_days_in_month[a._m-1] - a._d;

        // Then loop through the table adding the number of days in each month
        // until the end of the first year
        for(int i = a._m+1;i <= 12;i++)
            total_days += num_days_in_month[i-1];

        if (a._y != b._y)
        {
            // Done working with first year
            min_year++;
            // Loop through the years adding either 365 or 366
            // as appropriate until you reach the year of the parameter
            while (min_year < max_year)
            {
                total_days += 365;
                if (GetDayTableFromAYear(min_year)[1] == 29)
                    total_days++;
                min_year++;
            }
        }
    }
    num_days_in_month = b.GetDayTableFromAYear();
    // Loop through the parameter's months until you reach its month
    for(int i = 0;i < b._m;i++)
    {
        // Add the appropriate number of days
        if (i == b._m-1)
            total_days += b._d;
        else
            total_days += num_days_in_month[i];
    }

    return total_days;
}

