#include <iostream>

using namespace std;

struct sDate
{
    unsigned short day;
    unsigned short month;
    unsigned int year;
};

sDate ReadDate()
{
        sDate date;
        cout << "Please enter a day ";
        cin >> date.day;
        cout << "Please enter a month ";
        cin >> date.month;
        cout << "Please enter a year ";
        cin >> date.year;
        return date;
}

bool IsLeapYear(int year)
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

short DaysInMonth(short month, short year)
{
    short daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && IsLeapYear(year))
        return 29;
    return daysInMonth[month - 1];
}

bool IsTheLastDay(short day, short month)
{
    return day == DaysInMonth(month, day);
}

bool IsTheLastMonth(short month)
{
    return month == 12;
}

void IncreaseDateByOne(sDate &date)
{
    if (IsTheLastDay(date.day, date.month) && IsTheLastMonth(date.month))
    {
        date.day = 1;
        date.month = 1;
        date.year++;
    }
    else if (IsTheLastDay(date.day, date.month))
    {
        date.day = 1;
        date.month++;
    }
    else
        date.day++;
}

int main()
{
    sDate date = ReadDate();
    IncreaseDateByOne(date);
    cout << "\nDate after adding one day is : " << date.day << "/" << date.month << "/" << date.year;
    return 0;
}