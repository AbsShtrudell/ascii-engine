#include "Date.h"
#include <ctime>    
#pragma warning(disable : 4996)

Date::Date(int year, int month, int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::Date()
{
}

Date::~Date()
{
}

int Date::getYear()
{
    return Year;
}

int Date::getMonth()
{
    return Month;
}

int Date::getDay()
{
    return Day;
}

void Date::setYear(int year)
{
    Year = year;
}

void Date::setMonth(int month)
{
    if (month > 0 && month <= 12)
        Month = month;
}

void Date::setDay(int day)
{
    if (day > 0 and day <= DaysInMonth[Month - 1])
        Day  = day;
}

Date Date::Today()
{
    Date today;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    today.Year =1900 + ltm->tm_year;
    today.Month = 1 + ltm->tm_mon;
    today.Day = ltm->tm_mday;

    return today;
}

bool Date::operator>(const Date& date)
{
    if (Year > date.Year) return true;
    if (Year < date.Year) return false;

    else  if (Month > date.Month) return true;
    if (Month < date.Month) return false;
          
    else  if (Day > date.Day) return true;
    if (Day <= date.Day) return false;
    return false;
}

bool Date::operator<(const Date& date)
{
    if (Year < date.Year) return true;
    if (Year > date.Year) return false;

    else  if (Month < date.Month) return true;
    if (Month > date.Month) return false;

    else  if (Day < date.Day) return true;
    if (Day >= date.Day) return false;
    return false;
}

int Date::DaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };