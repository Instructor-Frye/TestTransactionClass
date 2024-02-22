#include "Date.h"
#include <string>
#include <iostream>

Date::Date()
{
	month = 1;
	day = 1;
	year = 1753;
}

Date::Date(int newMonth, int newDay, int newYear)
{
	Date();
	setDate(newMonth, newDay, newYear);
}


int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

int Date::getYear()
{
	return year;
}

void Date::setMonth(int newMonth)
{
	if (newMonth >= 1 && newMonth <= 12)
	{
		month = newMonth;
	}
}

void Date::setYear(int newYear)
{
	if (newYear > 1782)
	{
		year = newYear;
	}
}

void Date::setDay(int newDay)
{
	if (month == 1 || month == 3 || month == 5 ||
		month == 7 || month == 8 || month == 10 ||
		month == 12)
	{
		if (newDay >= 1 && newDay <= 31)
		{
			day = newDay;
		}
	}
	else if (month == 2 || month == 4 || month == 6 ||
		month == 9 || month == 11)
	{
		if (newDay >= 1 && newDay <= 30)
		{
			day = newDay;
		}
	}
	else if (month == 2)
	{
		if (year % 400 == 0 ||
			(year % 4 == 0 &&
				year % 100 != 0))
		{
			if (newDay >= 1 && newDay <= 29)
			{
				day = newDay;
			}
		}
		else
		{
			if (newDay >= 1 && newDay <= 28)
			{
				day = newDay;
			}
		}
	}
}

void Date::setDate(int newMonth, int newDay, int newYear)
{
	setMonth(newMonth);
	setYear(newYear);
	setDay(newDay);
}

std::string Date::toString()
{
	return std::to_string(month) + "/" +
		std::to_string(day) + "/" +
		std::to_string(year);
}

bool Date::operator==(Date otherDate)
{
	if (month == otherDate.month &&
		day == otherDate.day &&
		year == otherDate.year)
	{
		return true;
	}

	return false;
}

bool Date::operator>(Date otherDate)
{
	if (year > otherDate.year)
	{
		return true;
	}
	else if (year == otherDate.year &&
		month > otherDate.month)
	{
		return true;
	}
	else if (year == otherDate.year &&
		month == otherDate.month &&
		day > otherDate.day)
	{
		return true;
	}
	
	return false;
}

bool Date::operator<(Date otherDate)
{
	if (year < otherDate.year)
	{
		return true;
	}
	else if (year == otherDate.year &&
		month < otherDate.month)
	{
		return true;
	}
	else if (year == otherDate.year &&
		month == otherDate.month &&
		day < otherDate.day)
	{
		return true;
	}

	return false;
}

bool Date::operator>=(Date otherDate)
{
	if (year > otherDate.year)
	{
		return true;
	}
	else if (year == otherDate.year && month > otherDate.month)
	{
		return true;
	}
	else if (year == otherDate.year && month == otherDate.month && day >= otherDate.day)
	{
		return true;
	}

	return false;
}

bool Date::operator<=(Date otherDate)
{
	if (year < otherDate.year)
	{
		return true;
	}
	else if (year == otherDate.year && month < otherDate.month)
	{
		return true;
	}
	else if (year == otherDate.year && month == otherDate.month && day <= otherDate.day)
	{
		return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& os, Date& date)
{
	// write obj to stream
	os << date.toString();
	return os;
}
