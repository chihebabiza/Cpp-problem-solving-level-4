#include <iostream>
#include <ctime>

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
    cout << "\nPlease enter a day: ";
    cin >> date.day;
    cout << "Please enter a month: ";
    cin >> date.month;
    cout << "Please enter a year: ";
    cin >> date.year;
    return date;
}

sDate GetSystemDate()
{
    sDate date;
    time_t t = time(0);
    tm *now = localtime(&t);

    date.day = now->tm_mday;
    date.month = now->tm_mon + 1;
    date.year = now->tm_year + 1900;
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

bool IsTheLastDay(short day, short month, short year)
{
    return day == DaysInMonth(month, year);
}

bool IsTheLastMonth(short month)
{
    return month == 12;
}

bool IsBeforeDate(sDate date1, sDate date2)
{
    return (date1.year < date2.year) ||
           (date1.year == date2.year && date1.month < date2.month) ||
           (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}

void IncreaseDateByOne(sDate &date)
{
    if (IsTheLastDay(date.day, date.month, date.year) && IsTheLastMonth(date.month))
    {
        date.day = 1;
        date.month = 1;
        date.year++;
    }
    else if (IsTheLastDay(date.day, date.month, date.year))
    {
        date.day = 1;
        date.month++;
    }
    else
    {
        date.day++;
    }
}

int DiffYear(sDate date1, sDate date2, bool includeEnd = false)
{
    int days = 0;
    while (IsBeforeDate(date1, date2))
    {
        IncreaseDateByOne(date1);
        days++;
    }
    return includeEnd ? ++days : days;
}

int main()
{
    sDate date1 = ReadDate();
    sDate date2 = GetSystemDate();

    cout << "\nYour age is: " << DiffYear(date1, date2) << " day(s)";
    return 0;
}
