#pragma once

class Date
{
public:
	Date(int year, int month, int day);
	Date();
	~Date();

	int getYear();
	int getMonth();
	int getDay();

	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);

	static Date Today();

	bool operator>(const Date& date);
	bool operator<(const Date& date);
private:
	int Year = 2022;
	int Month = 01;
	int Day = 01;

	static int DaysInMonth[12];
};