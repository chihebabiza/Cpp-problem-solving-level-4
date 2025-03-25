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

stPeriod ReadPeriod()
{
    stPeriod period;
    cout << "\nEnter start date\n";
    period.startDate = ReadDate();
    cout << "\nEnter end date\n";
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

bool CheckDateInPeriod(stPeriod period, stDate date)
{
    return (!IsBeforeDate(date, period.startDate) && !IsBeforeDate(period.endDate, date));
}

int main()
{
    cout << "\nEnter period";
    stPeriod period = ReadPeriod();

    cout << "\nEnter date to check\n";
    stDate date = ReadDate();

    if (CheckDateInPeriod(period, date))
        cout << "\nYES , Date is within period";
    else
        cout << "\nNO , Date is NOT within period";
    return 0;
}
