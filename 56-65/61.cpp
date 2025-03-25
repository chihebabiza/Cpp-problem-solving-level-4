#include <iostream>

using namespace std;

struct stDate
{
    short day;
    short month;
    short year;
};

struct stPeriod
{
    stDate startDate;
    stDate endDate;
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

stPeriod ReadPeriod()
{
    stPeriod period;
    cout << "\nEnter start date ";
    period.startDate = ReadDate();
    cout << "\nEnter end date";
    period.endDate = ReadDate();
    return period;
}

bool IsBeforeDate(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ||
           (date1.year == date2.year && date1.month < date2.month) ||
           (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day);
}

bool IsEqual(stDate date1, stDate date2)
{
    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

bool IsAfterDate(stDate date1, stDate date2)
{
    return !IsBeforeDate(date1, date2) && !IsEqual(date1, date2);
}

short CompareDates(stDate date1, stDate date2)
{
    return IsEqual(date1, date2) ? 0 : (IsAfterDate(date1, date2) ? 1 : -1);
}

bool IsOverlap(stPeriod period1, stPeriod period2)
{
    return CompareDates(period1.endDate, period2.startDate) >= 0 &&
           CompareDates(period2.endDate, period1.startDate) >= 0;
}

stPeriod GetOverlapPeriod(stPeriod period1, stPeriod period2)
{
    stPeriod result;

    result.startDate = IsAfterDate(period1.startDate, period2.startDate) ? period1.startDate : period2.startDate;
    result.endDate = IsBeforeDate(period1.endDate, period2.endDate) ? period1.endDate : period2.endDate;

    if (IsAfterDate(result.startDate, result.endDate))
        result.startDate = result.endDate;

    return result;
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

int PeriodLength(stPeriod period, bool IncludeEnd = false)
{
    return IncludeEnd ? DiffDate(period.startDate, period.endDate) + 1 : DiffDate(period.startDate, period.endDate);
}

int OverlapDays(stPeriod period1, stPeriod period2)
{
    if (!IsOverlap(period1, period2))
        return 0;
        
    stPeriod overlapPeriod = GetOverlapPeriod(period1, period2);
    return PeriodLength(overlapPeriod);
}

int main()
{
    cout << "\nEnter period 1";
    stPeriod period1 = ReadPeriod();
    cout << "\nEnter period 2";
    stPeriod period2 = ReadPeriod();

    cout << "\nOverlap days is " << OverlapDays(period1, period2);
    return 0;
}