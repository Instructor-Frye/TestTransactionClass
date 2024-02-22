#pragma once
#include <string>
#include <iostream>

class Date
{
private:
    int month;
    int day;
    int year;
    void setMonth(int newMonth);
    void setYear(int newYear);
    void setDay(int newDay);
public:
    Date();
    Date(int newMonth, int newDay, int newYear);
    int getMonth();
    int getDay();
    int getYear();
    void setDate(int newMonth, int newDay, int newYear);
    std::string toString();
    bool operator==(Date otherDate);
    bool operator>(Date otherDate);
    bool operator<(Date otherDate);
    bool operator>=(Date otherDate);
    bool operator<=(Date otherDate);

    friend std::ostream& operator<<(std::ostream& os, Date& obj);
};


