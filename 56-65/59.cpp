#include <iostream>

using namespace std;

struct stDate
{
    short day;
    short month;
    int year;
};

struct stPeriod
{
    stDate startDate;
    stDate endDate;
};

stDate ReadDate()
{
    stDate date;
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

bool IsTheLastDay(short day, short month, short year)
{
    return day == DaysInMonth(month, year);
}

bool IsTheLastMonth(short month)
{
    return month == 12;
}

void IncreaseDateByOne(stDate &date)
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

bool IsEqual(stDate date1, stDate date2)
{
    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

int DiffDate(stDate date1, stDate date2)
{
    int days = 0;
    while (!IsEqual(date1, date2))
    {
        IncreaseDateByOne(date1);
        days++;
    }
    return days;
}

stPeriod ReadPeriod()
{
    stPeriod period;
    cout << "\nEnter start date\n";
    period.startDate = ReadDate();
    cout << "\nEnter end date\n";
    period.endDate = ReadDate();
    return period;
}

int PeriodLength(stPeriod period, bool IncludeEnd = false)
{
    return IncludeEnd ? DiffDate(period.startDate, period.endDate) + 1 : DiffDate(period.startDate, period.endDate);
}

int main()
{
    cout << "\nEner period 1 \n";
    stPeriod period1 = ReadPeriod();
    cout << "\nPeriod length is : " << PeriodLength(period1);
    cout << "\nPeriod length (Including end date) is : " << PeriodLength(period1, true);
    return 0;
}