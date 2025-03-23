#include <iostream>

using namespace std;

struct stDate
{
    short day;
    short month;
    short year;
};

stDate ReadDate()
{
    stDate date;
    cout << "\nPlease enter a day ";
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

int main()
{
    stDate date1 = ReadDate();

    if (IsTheLastDay(date1.day, date1.month))
        cout << "\nYES, Day is last day in the month";
    else
        cout << "\nNO, Day is NOT last day in the month";

    if (IsTheLastMonth(date1.month))
        cout << "\nYES, Month is last month in the month";
    else
        cout << "\nNO, Month is NOT last month in the month";

    return 0;
}