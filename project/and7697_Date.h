#ifndef AND7697_DATE_H_INCLUDED
#define AND7697_DATE_H_INCLUDED


#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Date
{
public:
    Date(int y, int m, int d) : year {y}, month {m}, day {d} {};
    int get_year();
    int get_month();
    int get_day();
    string to_string() const;
    string to_file() const;
    friend ostream& operator<<(ostream& ost, const Date& date_two);
private:
    int year;
    int month;
    int day;
};

#endif // AND7697_DATE_H_INCLUDED
