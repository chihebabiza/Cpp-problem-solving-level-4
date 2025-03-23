#include <iostream>
#include <ctime>

using namespace std;

struct stDate
{
    short day;
    short month;
    int year;
};

short ReadDay()
{
    short day;
    cout << "Please enter a day ";
    cin >> day;
    return day;
}

short ReadMonth()
{
    short month;
    cout << "Please enter a month ";
    cin >> month;
    return month;
}

int ReadYear()
{
    int year;
    cout << "Please enter a year ";
    cin >> year;
    return year;
}

stDate ReadFullDate()
{
    stDate date;
    date.day = ReadDay();
    date.month = ReadMonth();
    date.year = ReadYear();
    return date;
}

string GetWeekDayName(short number)
{
    switch (number)
    {
    case 0:
        return ("Sunday");
    case 1:
        return ("Monday");
    case 2:
        return ("Tuesday");
    case 3:
        return ("Wednesday");
    case 4:
        return ("Thursday");
    case 5:
        return ("Friday");
    case 6:
        return ("Saturday");
    default:
        return ("Invalid day number");
    }
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

short GetDayOfWeek(int year, int month, int day)
{
    if (month == 1 || month == 2)
    {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int h = (day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) - (2 * j)) % 7;

    return (h + 6) % 7;
}

short GetDayOfWeek(stDate Date)
{
    return GetDayOfWeek(Date.year, Date.month, Date.day);
}

bool IsWeekEnd(stDate Date)
{
    short weekDay = GetDayOfWeek(Date);
    return (weekDay == 5 || weekDay == 6);
}

bool IsTheLastDay(short day, short month)
{
    return day == DaysInMonth(month, day);
}

bool IsTheLastMonth(short month)
{
    return month == 12;
}

void IncreaseDateByOne(stDate &date)
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

stDate VacationEndDate(stDate Date, short days)
{
    while (days > 0)
    {
        if (!IsWeekEnd(Date))
            days--;
        IncreaseDateByOne(Date);
    }

    return Date;
}

short ReadVacationDays()
{
    short days;
    cout << "\nEnter vacation days ";
    cin >> days;
    return days;
}

int main()
{
    cout << "\nVacation start ?\n";
    stDate startDate = ReadFullDate();
    short days = ReadVacationDays();

    cout << "\n\nReturn date " << GetWeekDayName(GetDayOfWeek(VacationEndDate(startDate, days))) << " , " << VacationEndDate(startDate, days).day << "/" << VacationEndDate(startDate, days).month << "/" << VacationEndDate(startDate, days).year;

    return 0;
}