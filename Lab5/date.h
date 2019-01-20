#ifndef DATE_H
#define DATE_H
using namespace std;

class Date
{
private:
    int _y, _m, _d;

public:
    Date();
    Date(int y, int m, int d);
    void SetAll(int y, int m, int d);
    int GetYear();
    int GetMonth();
    int GetDay();
    void print(int option, ostream &out);
    void reverseDates(Date &a, Date &b);
    int* GetDayTableFromAYear(int = 0);
    int GetDayDifference(Date b);
};
#endif
