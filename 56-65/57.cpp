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

int main()
{
    cout << "\nEnter period 1";
    stPeriod period1 = ReadPeriod();
    cout << "\nEnter period 2";
    stPeriod period2 = ReadPeriod();

    if (IsOverlap(period1, period2))
        cout << "\nYES, Periods overlap";
    else
        cout << "\nNO, Periods are NOT overlap";

    return 0;
}