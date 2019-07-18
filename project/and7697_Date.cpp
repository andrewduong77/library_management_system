#include "and7697_Date.h"

int Date::get_year()
{
    return year;
}

int Date::get_month()
{
    return month;
}

int Date::get_day()
{
    return day;
}

string Date::to_string() const
{
    string out;
    ostringstream ost;
    ost << this->month << " " << this->day << " " << this->year;
    out = ost.str();
    return out;
}

string Date::to_file() const
{
    string out;
    ostringstream ost;
    ost << this->month << " " << this->day << " " << this->year;
    out = ost.str();
    return out;
}

ostream& operator<<(ostream& ost, const Date& date_two)
{
    ost << date_two.month << " " << date_two.day << " " << date_two.year;
    return ost;
}